// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "..\Public\TankPlayerController.h"

#define OUT

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if(!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing a tank: %s"), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) return;

	OUT FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) //Linetraces as a side effect
	{
		//UE_LOG(LogTemp, Warning, TEXT("HIT_LOCATION: %s"), *HitLocation.ToString());
	}
}


bool ATankPlayerController::GetSightRayHitLocation(OUT FVector& HitLocation) const
{
	//Get Crosshair position in viewport
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	//Translate crosshair position from viewport to world position ("Deproject")
	OUT FVector CameraWorldLocation;
	OUT FVector WorldDirection;
	if(DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, OUT CameraWorldLocation, OUT WorldDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *WorldDirection.ToString());
	}

	HitLocation = FVector(1.0);
	return true;
}