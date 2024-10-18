
#include "AI/MyAISubsystem.h"

#include "Kismet/GameplayStatics.h"
#include "AI/MyAIActor.h"
#include "GameFramework/Character.h"
#include "Health/DamageComponent.h"
#include "Health/HealthComponent.h"
#include "Player/PlayerCharacter.h"

UMyAISubsystem::UMyAISubsystem()
{
}

void UMyAISubsystem::Tick(float DeltaTime)
{
	//call the parent implementation
	Super::Tick(DeltaTime);

	//storage for all the AI actors of the world
	TArray<AActor*> AIActors;

	//get all AI actors of the world
	UGameplayStatics::GetAllActorsOfClass(this, AMyAIActor::StaticClass(), AIActors);

	//iterate through all the AI actors
	for (AActor* AIActor : AIActors)
	{
		//check if the AI actor is valid
		if (AMyAIActor* MyAIActor = Cast<AMyAIActor>(AIActor))
		{
			//get the player character
			ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

			//check if the player character is valid
			if (PlayerCharacter)
			{
				//get the direction from the AI actor to the player character
				FVector Direction = PlayerCharacter->GetActorLocation() - MyAIActor->GetActorLocation();

				//normalize the direction
				Direction.Normalize();

				//update the location of the AI actor
				MyAIActor->SetActorLocation(MyAIActor->GetActorLocation() + Direction * MyAIActor->Speed * DeltaTime, true);
			}
		}
	}

}


TStatId UMyAISubsystem::GetStatId() const
{
	return TStatId();
}

void UMyAISubsystem::ResolveOverlap(AActor* OverlappedActor, AActor* OtherActor, UPrimitiveComponent* OverlappedComponent, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//check if the overlapped actor is an AI actor
	if (AMyAIActor* MyAIActor = Cast<AMyAIActor>(OverlappedActor))
	{
		//check if the other actor is a player character
		if (APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor))
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
