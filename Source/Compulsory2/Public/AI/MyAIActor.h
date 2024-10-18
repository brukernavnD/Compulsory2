// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyAIActor.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AMyAIActor: public AActor
{
	GENERATED_BODY()
	
public:

	//the sphere component of the actor
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USphereComponent* SphereComponent;

	//the health component of the actor
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UHealthComponent* HealthComponent;

	//the damage component of the actor
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UDamageComponent* DamageComponent;

	//whether or not we should directly go to the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bChasePlayer = true;

	//the speed at which the actor should move
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 100.0f;

	//constructor(s)
	AMyAIActor();

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//override(s)
	virtual void BeginPlay() override;
};
