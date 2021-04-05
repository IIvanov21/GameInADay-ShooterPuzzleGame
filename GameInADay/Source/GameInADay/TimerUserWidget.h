// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TimerUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class GAMEINADAY_API UTimerUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(Category = UserInterface, EditAnywhere, BlueprintReadWrite)
		FString TimeDisplay;
	UPROPERTY(EditAnywhere)
		int Minutes;
	UPROPERTY(EditAnywhere)
		int Seconds;
	UFUNCTION()
		void GetTimer(int timerIn);
};
