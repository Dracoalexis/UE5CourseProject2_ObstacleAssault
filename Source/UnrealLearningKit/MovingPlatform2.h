// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform2.generated.h"

UCLASS()
class UNREALLEARNINGKIT_API AMovingPlatform2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category="Moving Platform");
	FVector PlatformVelocity = FVector(100,0,0);

	UPROPERTY(EditAnywhere, Category="Moving Platform");
	float MoveDistance = 100;
	UPROPERTY(EditAnywhere,Category="Rotation")
	FRotator RotationVelocity;

	FVector StartLocation;

	void MovePlatform(float DelatTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;

};
