// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "HealthSubsystem.generated.h"

UCLASS()
class UHealthSubsystem: public UTickableWorldSubsystem
{
	GENERATED_BODY()
	
public:

	//constructor
	UHealthSubsystem();

	//override(s)
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;
};