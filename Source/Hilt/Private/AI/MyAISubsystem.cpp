
#include "AI/MyAISubsystem.h"

#include "Kismet/GameplayStatics.h"
#include "AI/MyAIActor.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Health/DamageComponent.h"
#include "Health/HealthComponent.h"
#include "Player/PlayerCharacter.h"

UMyAISubsystem::UMyAISubsystem()
{
}

void UMyAISubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	//cal the parent implementation
	Super::OnWorldBeginPlay(InWorld);

	//get all the AI actors of the world
	UGameplayStatics::GetAllActorsOfClass(this, AMyAIActor::StaticClass(), AIActors);

	//fill the velocities array with zero vectors
	Velocities.Init(FVector::ZeroVector, AIActors.Num());

	//fill the speeds array with the default speed
	Speeds.Init(DefaultSpeed, AIActors.Num());

	//fill the chase players array with the default chase player flag
	ChasePlayers.Init(DefaultChasePlayer, AIActors.Num());

	//iterate through all the AI actors
	for (AActor* AIActor : AIActors)
	{
		//cast the AI actor to a MyAIActor
		const AMyAIActor* MyAIActor = Cast<AMyAIActor>(AIActor);

		//add the start location of the AI actor to the start locations array
		StartLocations.Add(MyAIActor->GetActorLocation());
	}
}

void UMyAISubsystem::Tick(const float DeltaTime)
{
	//call the parent implementation
	Super::Tick(DeltaTime);

	//iterate through all the AI actors
	for (int Index = 0; Index < AIActors.Num(); ++Index)
	{
		//check if the AI actor is valid
		if (AMyAIActor* MyAIActor = Cast<AMyAIActor>(AIActors[Index]))
		{
			//get the player character and check if it's valid
			if (const ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0))
			{
				//get the direction from the AI actor to the player character
				FVector Direction = PlayerCharacter->GetActorLocation() - MyAIActor->GetActorLocation();

				//normalize the direction
				Direction.Normalize();

				//set the velocity of the AI actor
				Velocities[Index] = Direction * Speeds[Index];

				//update the AI actors location
				MyAIActor->SetActorLocation(MyAIActor->GetActorLocation() + Velocities[Index] * DeltaTime);

				//rotate the AI to face the player
				MyAIActor->SetActorRotation(Direction.Rotation());
			}
		}
	}

}


TStatId UMyAISubsystem::GetStatId() const
{
	return TStatId();
}

void UMyAISubsystem::ResetAIActors()
{
	//iterate through all the AI actors
	for (AActor* AIActor : AIActors)
	{
		//check if the AI actor is valid
		if (!AIActor)
		{
			//return early
			return;
		}

		//destroy the AI actor
		AIActor->Destroy();
	}

	//get the player character as a player character
	const APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	//empty the AI actors array
	AIActors.Empty();

	//iterate through all the start locations
	for (int Index = 0; Index < StartLocations.Num(); ++Index)
	{
		//spawn a new AI actor at the start location
		AActor* AIActor = GetWorld()->SpawnActor(PlayerCharacter->AIActorClass, &StartLocations[Index]);

		//cast the AI actor to a MyAIActor
		AMyAIActor* MyAIActor = Cast<AMyAIActor>(AIActor);

		//add the AI actor to the AI actors array
		AIActors.Add(MyAIActor);
	}
}

void UMyAISubsystem::ResolveOverlap(AActor* OverlappedActor, AActor* OtherActor, UPrimitiveComponent* OverlappedComponent, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//check if the overlapped actor is an AI actor
	if (const AMyAIActor* MyAIActor = Cast<AMyAIActor>(OverlappedActor))
	{
		//check if the other actor is a player character
		if (const APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor))
		{
			//check if the player character can take damage
			if (PlayerCharacter->HealthComponent->bCanTakeDamage)
			{
				//deal damage to the player character
				PlayerCharacter->HealthComponent->Health -= MyAIActor->DamageComponent->DealingDamage;
			}
			else
			{
				//deal damage to the AI actor
				MyAIActor->HealthComponent->Health -= PlayerCharacter->DamageComponent->DealingDamage;
			}

		}
	}
}
