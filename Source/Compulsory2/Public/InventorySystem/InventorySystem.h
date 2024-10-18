

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InventorySystem.generated.h"

class UInventoryComponent;
struct FSlotStruct;

//interface for actors(ai) that listen to pickup events
UINTERFACE()
class UListenForItemPickUp : public UInterface
{
	GENERATED_BODY()
};

class IListenForItemPickUp
{
	GENERATED_BODY()

public:

	//the name of the function to call
	FName DefaultInvUFunc;
};

/**
 * 
 */
UCLASS()
class UInventorySystem : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	//function to transfer the contents of 1 slot to another
	UFUNCTION(BlueprintCallable, Category = "Inventory System")
	static bool TransferSlotContents(FSlotStruct& FromSlot, FSlotStruct& ToSlot);
	
	//function to add a pickup event to an inventory component
	UFUNCTION(BlueprintCallable, Category = "Inventory System")
	static void AddPickupEvent(UInventoryComponent* InventoryComponent, AActor* InActor, const FName UFuncName);
	
	//function to add items to an inventory
	UFUNCTION(BlueprintCallable)
	static void AddToInventory(UInventoryComponent* InventoryComponent, UPARAM(ref) TArray<FSlotStruct>& FromInventory);

	//function to take items from an inventory
	UFUNCTION(BlueprintCallable)
	static bool TakeFromInventory(UInventoryComponent* InventoryComponent, TArray<FSlotStruct> ItemsToTake);
};
