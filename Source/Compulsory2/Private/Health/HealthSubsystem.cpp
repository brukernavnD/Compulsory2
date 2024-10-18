
#include "Health/HealthSubsystem.h"

#include "Kismet/GameplayStatics.h"
#include "Health/HealthComponent.h"

UHealthSubsystem::UHealthSubsystem()
{
}

void UHealthSubsystem::Tick(float DeltaTime)
{
	//call the parent implementation
	Super::Tick(DeltaTime);

	//get all the actors of the world
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsWithTag(this, "ECS", Actors);

	//iterate through all the actors
	for (AActor* Actor : Actors)
	{
		// //check if the Health component of the actor is valid
		// if (const UHealthComponent* Component = Actor->FindComponentByClass<UHealthComponent>())
		// {
		// 	//update the location of the actor
		// 	Actor->SetActorLocation(Actor->GetActorLocation() + Component->Velocity * DeltaTime, true);
		// }
	}
}

TStatId UHealthSubsystem::GetStatId() const
{
	return TStatId();
}
