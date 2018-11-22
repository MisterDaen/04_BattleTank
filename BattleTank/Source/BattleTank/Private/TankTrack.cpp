// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Components/StaticMeshComponent.h"

void UTankTrack::SetThrottle(float Throttle)
{
	// TODO clamp actual throttle so player can't over-drive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


