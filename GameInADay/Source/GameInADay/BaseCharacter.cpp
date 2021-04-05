// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Animation/AnimBlueprintGeneratedClass.h"
#include "Components/SceneCaptureComponent2D.h"
#include "AnimInstanceBase.h"
#include "DestructibleActor.h"
#include "EnemyCharacterBase.h"
#include "CoinActor.h"
#include "PuzzleActor.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Main Camera"));
	Camera->SetupAttachment(SpringArm);

	MapArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Map Arm"));
	MapArm->SetupAttachment(RootComponent);

	MiniMapCamera = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("MiniMap Camera"));
	MiniMapCamera->SetupAttachment(MapArm);
	
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	USkeletalMeshComponent* mesh = GetMesh();
	AnimationUpdate = Cast<UAnimInstanceBase>(GetMesh()->GetAnimInstance());

	StartLocation = GetActorLocation();
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForwards"), this, &ABaseCharacter::MoveForwards);
	PlayerInputComponent->BindAxis(TEXT("Strafe"), this, &ABaseCharacter::Strafe);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ABaseCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ABaseCharacter::Turn);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Respawn"), IE_Released, this, &ABaseCharacter::Respawn);

	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Pressed, this, &ABaseCharacter::StartCrouch);
	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Released, this, &ABaseCharacter::EndCrouch);


	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ABaseCharacter::Fire);
}

void ABaseCharacter::Strafe(float AxisAmount)
{
	AddMovementInput(GetActorRightVector() * AxisAmount);
}

void ABaseCharacter::Turn(float AxisAmount)
{
	AddControllerYawInput(AxisAmount);
}

void ABaseCharacter::LookUp(float AxisAmount)
{
	AddControllerPitchInput(AxisAmount);
}

void ABaseCharacter::MoveForwards(float AxisAmount)
{
	AddMovementInput(GetActorForwardVector() * AxisAmount);
}

void ABaseCharacter::StartCrouch()
{
	UE_LOG(LogTemp, Warning, TEXT("Crouch"));
	Crouch();
	
	if (AnimationUpdate)AnimationUpdate->Crouched();
}

void ABaseCharacter::EndCrouch()
{
	UE_LOG(LogTemp, Warning, TEXT("End Crouch"));
	UnCrouch();
	AnimationUpdate->UnCrouched();
}

void ABaseCharacter::Respawn()
{
	SetActorLocation(StartLocation);
}

void ABaseCharacter::Fire()
{
	AController* ControllerRef = GetController();
	FVector CameraLocation;
	FRotator CameraRotation;
	ControllerRef->GetPlayerViewPoint(CameraLocation, CameraRotation);

	float CastRange = 10000.0f;
	FVector EndPoint = CameraLocation + CameraRotation.Vector() * CastRange;

	FHitResult Hit;
	bool bDidHit = GetWorld()->LineTraceSingleByChannel(Hit, CameraLocation, EndPoint, ECC_Visibility);
	if (bDidHit)
	{
		if (Hit.GetActor())
		{
			FString ActorName = *Hit.GetActor()->GetName();
			UE_LOG(LogTemp, Warning, TEXT("Hit something: %s"), *ActorName);
			if(ActorName == "EndGamePoint")UGameplayStatics::OpenLevel(GetWorld(), "WinMenu");
			if (Cast<AEnemyCharacterBase>(Hit.GetActor()))
			{
				Cast<AEnemyCharacterBase>(Hit.GetActor())->TakeDamage(20);
			}
			else UE_LOG(LogTemp, Warning, TEXT("Invalid cast"));
		}
		
		if (Cast<ADestructibleActor>(Hit.GetActor()))Cast<ADestructibleActor>(Hit.GetActor())->Explode();
		if (Cast<ACoinActor>(Hit.GetActor()))Cast<ACoinActor>(Hit.GetActor())->AddPoints();
		if (Cast<APuzzleActor>(Hit.GetActor()))Cast<APuzzleActor>(Hit.GetActor())->Rotate();
	}
	else UE_LOG(LogTemp, Warning, TEXT("MISS!"));
}

