// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	float noise = FMath::RandRange(float(0.4), float(1.6));
	NewLocation.Z += DeltaHeight * 20.0f;
	NewLocation.X += DeltaHeight * 10.0f;
	NewLocation.Y += DeltaHeight * 15.0f;
	RunningTime += DeltaTime * noise;
	SetActorLocation(NewLocation);
}

