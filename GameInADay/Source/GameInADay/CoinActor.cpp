// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinActor.h"
#include "PlayerControllerBase.h"
// Sets default values
ACoinActor::ACoinActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coin Mesh"));
	CoinMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACoinActor::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = Cast<APlayerControllerBase>(GetWorld()->GetFirstPlayerController());

}

// Called every frame
void ACoinActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator RotateCoin = FRotator(0.0f, 2.0f, 0.0f);
	CoinMesh->AddRelativeRotation(RotateCoin);
}

void ACoinActor::AddPoints()
{
	PlayerController->SetScore(35);
	Destroy();

}

