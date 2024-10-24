


#include "InventorySystem/InventorySystem.h"

#include "InventorySystem/InventoryComponent.h"
#include "InventorySystem/ItemBase.h"


bool UInventorySystem::TransferSlotContents(FSlotStruct& FromSlot, FSlotStruct& ToSlot)
{
	//we have valid data to send
	if (FromSlot.Quantity <= 0 || FromSlot.Item == nullptr)
	{
		return false;
	}

	//make destination hold our item if it has no item
	if (ToSlot.Item == nullptr || ToSlot.Quantity == 0)
	{
		ToSlot = FromSlot;
		FromSlot = FSlotStruct();
	}

	//abort if destination has its own item
	else if (ToSlot.Item != FromSlot.Item)
	{
		return false;
	}

	//abort if destination has no extra capacity
	else if (ToSlot.Quantity >= ToSlot.Item->MaxQuantity)
	{
		return false;
	}

	const int AvailableCapacity = ToSlot.Item->MaxQuantity - ToSlot.Quantity;

	for (int i = 0; i < AvailableCapacity; ++i)
	{
		if (FromSlot.Quantity > 0 && ToSlot.Quantity <= ToSlot.Item->MaxQuantity)
		{
			FromSlot.Quantity--;
			ToSlot.Quantity++;
			if (FromSlot.Quantity == 0)
			{
				FromSlot = FSlotStruct();
				return true;
			}
		}
	}
	return false;
}

void UInventorySystem::AddPickupEvent(UInventoryComponent* InventoryComponent, AActor* InActor, const FName UFuncName)
{
	//bind the event
	InventoryComponent->MajorItemPickedUpEvent.AddUFunction(InActor, UFuncName);
}

void UInventorySystem::AddToInventory(UInventoryComponent* InventoryComponent, TArray<FSlotStruct>& FromInventory)
{
	//iterate through the slots
	for (FSlotStruct& InSlotStruct : FromInventory)
	{
		//check if we have valid data
		if (InSlotStruct)
		{
			//get the tags
			TArray<FGameplayTag> Tags;
			InSlotStruct.Item->PickUpTags.GetGameplayTagArray(Tags);

			//iterate through the tags
			for (const FGameplayTag Tag : Tags)
			{
				//broadcast the events
				InventoryComponent->MajorItemPickedUpEvent.Broadcast(InSlotStruct, InventoryComponent->GetOwner(), Tag);
			}

			//iterate through the inventory
			for (FSlotStruct& SlotStruct : InventoryComponent->Inventory)
			{
				//transfer the contents
				if (TransferSlotContents(InSlotStruct, SlotStruct))
				{
					break;
				}
			}
		}
	}
}

bool UInventorySystem::TakeFromInventory(UInventoryComponent* InventoryComponent, TArray<FSlotStruct> ItemsToTake)
{
	//iterate through the items
	for (FSlotStruct& InSlotStruct : ItemsToTake)
	{
		//check if we have valid data
		if (InSlotStruct)
		{
			//iterate through the inventory
			for (FSlotStruct& SlotStruct : InventoryComponent->Inventory)
			{
				//check if we have valid data
				if (SlotStruct)
				{
					//check if the items match
					if (InSlotStruct.Item == SlotStruct.Item)
					{
						//iterate through the quantity
						for (int i = 0; i < InSlotStruct.Quantity; ++i)
						{
							//check if we have valid data
							if (SlotStruct.Quantity > 0)
							{
								//decrement the quantities
								InSlotStruct.Quantity--;
								SlotStruct.Quantity--;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
