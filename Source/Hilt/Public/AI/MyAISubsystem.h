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

	//list of all the ai actors in the world
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<AActor*> AIActors;

	//list of all the velocites of the ai actors
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FVector> Velocities;

	//list of all the speeds of the ai actors
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<float> Speeds;

	//list of all the chase player flags of the ai actors
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<bool> ChasePlayers;

	//list of all the start locations of the ai actors
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FVector> StartLocations;

	//the default speed of the ai actors
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DefaultSpeed = 900;

	//the default chase player flag of the ai actors
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool DefaultChasePlayer = true;

	//constructor
	UMyAISubsystem();

	//override(s)
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;

	//function to reset all ai actors
	UFUNCTION()
	void ResetAIActors();

	//static function to resolve overlap
	UFUNCTION()
	static void ResolveOverlap(AActor* OverlappedActor, AActor* OtherActor, UPrimitiveComponent* OverlappedComponent, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};