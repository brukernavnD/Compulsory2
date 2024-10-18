// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventorySystem/ItemBase.h"
#include "DefaultItemActor.generated.h"

UCLASS()
class ADefaultItemActor : public AActor
{
	GENERATED_BODY()

public:	
	//constructor(s)
	ADefaultItemActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSlotStruct> Items;

	//function to transfer the items of this actor to another actor
	UFUNCTION(BlueprintCallable)
	void PickUpItem(AActor* ReceivingActor);
};
