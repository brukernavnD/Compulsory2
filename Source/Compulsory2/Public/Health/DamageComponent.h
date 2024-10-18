// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UDamageComponent: public UActorComponent
{
	GENERATED_BODY()
	
public:

	//the damage this actor deals on collision
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DealingDamage = 15;

	//constructor
	UDamageComponent();
};
