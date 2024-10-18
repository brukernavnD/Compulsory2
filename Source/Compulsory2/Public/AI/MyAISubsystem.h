// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "MyAISubsystem.generated.h"

UCLASS()
class UMyAISubsystem: public UTickableWorldSubsystem
{
	GENERATED_BODY()
	
public:

	//constructor
	UMyAISubsystem();

	//override(s)
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;

	//static function to resolve overlap
	UFUNCTION()
	static void ResolveOverlap(AActor* OverlappedActor, AActor* OtherActor, UPrimitiveComponent* OverlappedComponent, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};