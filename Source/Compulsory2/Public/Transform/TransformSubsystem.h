// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "TransformSubsystem.generated.h"

class UTransformComponent;

UCLASS()
class UTransformSubsystem: public UTickableWorldSubsystem
{
	GENERATED_BODY()
	
public:

	//constructor
	UTransformSubsystem();

	//override(s)
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;
};