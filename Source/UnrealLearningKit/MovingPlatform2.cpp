// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform2.h"

// Sets default values
AMovingPlatform2::AMovingPlatform2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform2::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("Configured Move Distance:%f"),MoveDistance);
	
}

// Called every frame
void AMovingPlatform2::Tick(float DeltaTime)
{	
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);

	RotatePlatform(DeltaTime);

}

void AMovingPlatform2::MovePlatform(float DeltaTime)
{

	if(ShouldPlatformReturn())
	{		
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);PlatformVelocity = -PlatformVelocity;
	}
	else{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform2::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlatform2::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MoveDistance;
}

float AMovingPlatform2::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}