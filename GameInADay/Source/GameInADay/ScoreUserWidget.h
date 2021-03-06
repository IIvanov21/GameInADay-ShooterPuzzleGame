// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class GAMEINADAY_API UScoreUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(Category = UserInterface, EditAnywhere, BlueprintReadWrite)
		FString Score;
	UPROPERTY(EditAnywhere)
		int CurrentScore=0;
	void UpdateScore(int Points);
};
