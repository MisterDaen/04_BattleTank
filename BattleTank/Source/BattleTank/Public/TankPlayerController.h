// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

// Forward Declarations
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	// starts the movement of the barrel so that a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();

private:
	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.f;

	// return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	// returns an OUT parameter, location being looked at
	bool GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const;

	// returns an OUT parameter, hit location at cursor
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
