// Fill out your copyright notice in the Description page of Project Settings.

#include "InventorySystem/DefaultItemActor.h"

#include "InventorySystem/ItemBase.h"
#include "InventorySystem/InventoryComponent.h"
#include "InventorySystem/InventorySystem.h"

ADefaultItemActor::ADefaultItemActor()
{

}

void ADefaultItemActor::PickUpItem(AActor* ReceivingActor)
{
	//check if we have no items (this shouldn't happen)
	if (Items.Num() == 0)
	{
		//print a debug message
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, this->GetActorNameOrLabel() + " Has No Items");

		//return early to prevent further execution
		return;
	}

	//get the inventory components of the receiving actor
	TArray<UInventoryComponent*> InvComponents;
	ReceivingActor->GetComponents<UInventoryComponent>(InvComponents);

	//iterate over the inventory components
	for (UInventoryComponent* InvComponent : InvComponents)
	{
		//check if the inventory comoponent can pick up items
		if (InvComponent->CanPickUp)
		{
			//add as many items as we can to the inventory systems
			UInventorySystem::AddToInventory(InvComponent, Items);

			//check if we have transfered all our items
			if (Items.IsValidIndex(0) && !Items[0])
			{
				//destoy ourselves
				Destroy();

				//return to prevent further exection
				return;
			}
		}
	}
}
