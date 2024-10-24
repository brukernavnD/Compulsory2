// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "Engine/Texture2D.h"
#include "ItemBase.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UItemBase : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:

    //the max quantity for this item in 1 inventory slot
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int MaxQuantity = 64;

    //the image for this item
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UTexture2D* MyImage = nullptr;

    //the debug message for this item
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FString MyDebugMsg = "this is a debug msg";

    //the gameplay tags to send when this item is picked up
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTagContainer PickUpTags;
};

//the struct for a inventory slot
USTRUCT(blueprinttype)
struct FSlotStruct
{
    GENERATED_BODY()

    //the item we have
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UItemBase* Item = nullptr;

    //the amount of the item we have
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int Quantity = 0;

    //constructor(s)
    FSlotStruct();
    FSlotStruct(const int quantity, UItemBase* item);
    explicit FSlotStruct(UItemBase* item);

    ////function to try to transfer the contents of this slot to another slot
    //bool TransferContentsTo(FSlotStruct& Destination);

    //operator overloads
    void operator=(FSlotStruct ToBe);
    void operator=(nullptr_t Nullptr);
    explicit operator bool() const;
    friend bool operator==(const FSlotStruct &lhs, const FSlotStruct &rhs);
};
