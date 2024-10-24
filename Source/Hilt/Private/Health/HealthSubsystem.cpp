
#include "Health/HealthSubsystem.h"

#include "Kismet/GameplayStatics.h"
#include "Health/HealthComponent.h"
#include "Player/PlayerCharacter.h"

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
		//check if the actor has a health component
		if (UHealthComponent* HealthComponent = Actor->FindComponentByClass<UHealthComponent>())
		{
			//check if the health is below or equal to zero
			if (HealthComponent->Health <= 0)
			{
				//check if the actor is not a player character
				if (!Actor->IsA<APlayerCharacter>())
				{
					//destroy the actor
					Actor->Destroy();
				}
				else
				{
					//cast the actor to a player character
					APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(Actor);

					//create input action value
					FInputActionValue InputActionValue;

					//call the restart function
					PlayerCharacter->RestartGame(InputActionValue);
				}
			}
		}
	}
}

TStatId UHealthSubsystem::GetStatId() const
{
	return TStatId();
}
