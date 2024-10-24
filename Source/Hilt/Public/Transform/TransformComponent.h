// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TransformComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UTransformComponent: public UActorComponent
{
	GENERATED_BODY()
	
public:

	//the velocity of the actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Velocity;

	//constructor
	UTransformComponent();
};
