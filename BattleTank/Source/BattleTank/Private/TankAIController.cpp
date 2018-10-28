// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	// UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));

	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	// log the tank pawn being possessed
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s."), *(ControlledTank->GetName()));
	}

	// log the tank pawn being targeted
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not targeting a player tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController targeting: %s."), *(PlayerTank->GetName()));
	}
}

// called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		// TODO move towards the player

		// aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// fire when ready
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}