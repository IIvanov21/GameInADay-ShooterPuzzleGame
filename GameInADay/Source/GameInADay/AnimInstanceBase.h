// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class GAMEINADAY_API UAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool IsCrouching;
	// Called to bind functionality to input
public:
	UFUNCTION(BlueprintCallable, Category = "UpdateAnimationProperties")
		void UpdateAnimationProperties();
	UFUNCTION(BlueprintCallable, Category = "UpdateCrouch")
		void Crouched();
	UFUNCTION(BlueprintCallable, Category = "UpdateCrouch")
		void UnCrouched();
};
