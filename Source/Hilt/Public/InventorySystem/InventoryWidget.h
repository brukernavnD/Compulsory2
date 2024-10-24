// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

class USlotWidget;
class UInventoryComponent;

/**
 * Widget for displaying the inventory system
 */
UCLASS(Blueprintable)
class UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	//the inventory component that contains the inventory we use
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn))
	UInventoryComponent* OwnerInventory;

	//the widget used for displaying a slot
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<USlotWidget> SlotWidget;
};
