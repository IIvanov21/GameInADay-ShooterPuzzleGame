// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzleActor.h"

// Sets default values
APuzzleActor::APuzzleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PuzzleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Puzzle Mesh"));
	PuzzleMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APuzzleActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuzzleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APuzzleActor::Rotate()
{
	FRotator RotatePuzzle = FRotator(0.0f, 90.0f, 0.0f);
	PuzzleMesh->AddLocalRotation(RotatePuzzle);
}