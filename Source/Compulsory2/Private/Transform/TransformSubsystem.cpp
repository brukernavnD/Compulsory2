
#include "Transform/TransformSubsystem.h"

#include "Kismet/GameplayStatics.h"
#include "Transform/TransformComponent.h"

UTransformSubsystem::UTransformSubsystem()
{
}

void UTransformSubsystem::Tick(float DeltaTime)
{
	//call the parent implementation
	Super::Tick(DeltaTime);

	//get all the actors of the world
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsWithTag(this, "ECS", Actors);

	//iterate through all the actors
	for (AActor* Actor : Actors)
	{
		//check if the transform component of the actor is valid
		if (const UTransformComponent* Component = Actor->FindComponentByClass<UTransformComponent>())
		{
			//update the location of the actor
			Actor->SetActorLocation(Actor->GetActorLocation() + Component->Velocity * DeltaTime, true);
		}
	}
}

TStatId UTransformSubsystem::GetStatId() const
{
	return TStatId();
}
