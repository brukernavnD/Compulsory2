// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SlotWidget.generated.h"

class UInventoryComponent;

/**
 * The widget for displaying a slot
 */
UCLASS()
class USlotWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	//the inventory component that holds the items we have
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn))
	UInventoryComponent* OwnerInventory;

	//the index of our slot
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn))
	int	InvIndex;
};
