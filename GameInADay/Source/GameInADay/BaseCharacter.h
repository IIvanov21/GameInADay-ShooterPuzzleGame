// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"
class UAnimInstanceBase;
class USpringArmComponent;
class UCameraComponent;
class USceneCaptureComponent2D;
UCLASS()
class GAMEINADAY_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* MapArm;
	UPROPERTY(EditAnywhere)
		USceneCaptureComponent2D* MiniMapCamera;
	UPROPERTY(EditAnywhere)
		UAnimInstanceBase* AnimationUpdate;
	UPROPERTY(EditAnywhere)
		FVector StartLocation;

private:
	//Character Move Functions
	void Strafe(float AxisAmount);
	void Turn(float AxisAmount);
	void LookUp(float AxisAmount);
	void MoveForwards(float AxisAmount);
	void StartCrouch();
	void EndCrouch();
	void Respawn();
	//Motion functions
	void Fire();
};
