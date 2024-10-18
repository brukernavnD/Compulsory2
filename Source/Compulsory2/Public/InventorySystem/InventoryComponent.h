// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "Components/ActorComponent.h"
#include "InventorySystem/ItemBase.h"
#include "InventoryComponent.generated.h"


class UInventoryWidget;



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	//event declarations
	DECLARE_EVENT_ThreeParams(ADefaultItemActor, FMajorItemPickedUpEvent, FSlotStruct&, AActor*, FGameplayTag)

	//the gameplay tag used for sending the event to other actors
	static inline FName PickupEventAbleTag = "PickupEventable";

	//whether we can pick up items or not
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanPickUp = false;

	//whether or not we can bind events to this component
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool EventBindable = true;

	//the items we have
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSlotStruct> Inventory;

	//the class of widget to use for the inventory
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UInventoryWidget> InventoryWidget;

	//the active widget used by this component
	UPROPERTY()
	UInventoryWidget* InvWidget = nullptr;

	FMajorItemPickedUpEvent& OnMajorItemPickedUp() { return MajorItemPickedUpEvent; }

	//the event for when this component picks up a major item
	FMajorItemPickedUpEvent MajorItemPickedUpEvent;

	//constructor(s)
	UInventoryComponent();

	//override(s)
	virtual void BeginPlay() override;

	//template <typename UObjectTemplate>
	//void AddPickUpEventBinding(UObjectTemplate* InUserObject, const FName UFuncName);

	//UFUNCTION(BlueprintCallable)
	//void AddToInventory(UPARAM(ref) TArray<FSlotStruct>& InInventory);

	//UFUNCTION(BlueprintCallable)
	//bool TakeFromInventory(TArray<FSlotStruct> ItemsToTake);

	UFUNCTION(BlueprintCallable)
	void ToggleInventoryWidget();
};

////template function to bind add event to this component
//template <typename UObjectTemplate>
//void UInventoryComponent::AddPickUpEventBinding(UObjectTemplate* InUserObject, const FName UFuncName)
//{
//	this->MajorItemPickedUpEvent.AddUFunction(InUserObject, UFuncName);
//	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("test 4"));
//}
