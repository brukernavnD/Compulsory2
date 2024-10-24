// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HealthComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UHealthComponent: public UActorComponent
{
	GENERATED_BODY()
	
public:

	//the health of the actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Health = 100;

	//the max health of the actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxHealth = 100;

	//whether or not this components owner can take damage right now
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanTakeDamage = true;

	//whether or not this components owner is dead right now
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsDead = false;

	//constructor
	UHealthComponent();
};
