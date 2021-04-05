// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacterBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerControllerBase.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AEnemyCharacterBase::AEnemyCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Main Camera"));
	Camera->SetupAttachment(SpringArm);
	EnemyHealth = 100;
	auto pWorld = GetWorld();
	
}

// Called when the game starts or when spawned
void AEnemyCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = Cast<APlayerControllerBase>(GetWorld()->GetFirstPlayerController());
	
}

// Called every frame
void AEnemyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AEnemyCharacterBase::TakeDamage(int DamageTaken)
{
	if (EnemyHealth > 0)
	{
		EnemyHealth -= DamageTaken;
		if (EnemyHealth <= 0)
		{
			PlayerController->SetScore(20);

			Destroy();
		}
	}
	else
	{
		PlayerController->SetScore(20);
		Destroy();

	}

}
