// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySystem/InventoryComponent.h"
#include "InventorySystem/InventorySystem.h"
#include "InventorySystem/InventoryWidget.h"
#include "Kismet/GameplayStatics.h"

UE_DEFINE_GAMEPLAY_TAG(TAG_ItemPickUp_Major, "ItemPickUp.Major");

UInventoryComponent::UInventoryComponent()
{

}

void UInventoryComponent::BeginPlay()
{
	//call the parent implementation
	Super::BeginPlay();

	//check if we should bind events and we can pick up items
	if (EventBindable && CanPickUp)
	{
		//get all actors with the listen for item pick up interface
		TArray<AActor*> Actors;
		UGameplayStatics::GetAllActorsWithInterface(this, UListenForItemPickUp::StaticClass(), Actors);

		//iterate over the actors
		for (AActor* Actor : Actors)
		{
			//add their inventory function to our binding
			UInventorySystem::AddPickupEvent(this, Actor, Cast<IListenForItemPickUp>(Actor)->DefaultInvUFunc);
		}
	}
}

//void UInventoryComponent::AddToInventory(TArray<FSlotStruct>& InInventory)
//{
//	for (FSlotStruct& InSlotStruct : InInventory)
//	{
//		if (InSlotStruct)
//		{
//			TArray<FGameplayTag> Tags;
//			InSlotStruct.Item->PickUpTags.GetGameplayTagArray(Tags);
//			for (const FGameplayTag Tag : Tags)
//			{
//				MajorItemPickedUpEvent.Broadcast(InSlotStruct, GetOwner(), Tag);
//			}
//			for (FSlotStruct& SlotStruct : Inventory)
//			{
//				if (InSlotStruct.TransferContentsTo(SlotStruct))
//				{
//					break;
//				}
//			}
//		}
//	}
//}

//bool UInventoryComponent::TakeFromInventory(TArray<FSlotStruct> ItemsToTake)
//{
//	for (FSlotStruct& InSlotStruct : ItemsToTake)
//	{
//		if (InSlotStruct)
//		{
//			for (FSlotStruct& SlotStruct : Inventory)
//			{
//				if (SlotStruct)
//				{
//					if (InSlotStruct.Item == SlotStruct.Item)
//					{
//						for (int i = 0; i < InSlotStruct.Quantity; ++i)
//						{
//							if (SlotStruct.Quantity > 0)
//							{
//								InSlotStruct.Quantity--;
//								SlotStruct.Quantity--;
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return false;
//}

void UInventoryComponent::ToggleInventoryWidget()
{
	if (!InvWidget)
	{
		InvWidget = CreateWidget<UInventoryWidget>(GetWorld()->GetFirstPlayerController(), InventoryWidget);
		InvWidget->OwnerInventory = this;
		InvWidget->AddToViewport();
	}
	else if (!InvWidget->IsInViewport())
	{
		InvWidget->AddToViewport();
	}
	else
	{
		InvWidget->RemoveFromParent();
	}
}
