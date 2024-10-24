// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyAIActor.generated.h"

UCLASS()
class AMyAIActor: public AActor
{
	GENERATED_BODY()
	
public:

	//the health component of the actor
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UHealthComponent* HealthComponent;

	//the damage component of the actor
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UDamageComponent* DamageComponent;

	//the sphere component used for collision
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USphereComponent* SphereComponent;

	//the mesh component of the actor
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* MeshComponent;

	//constructor(s)
	AMyAIActor();

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//override(s)
	virtual void BeginPlay() override;
};
