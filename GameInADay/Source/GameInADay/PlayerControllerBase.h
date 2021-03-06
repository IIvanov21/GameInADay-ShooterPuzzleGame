// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */

class UScoreUserWidget;
class UTimerUserWidget;
UCLASS()
class GAMEINADAY_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	void SetScore(int Points);
	void  SetTimer(int timeIn);

private:
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> CrosshairClass;
	UPROPERTY(EditAnywhere)
		UUserWidget* CrosshairUI;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> MinimapClass;
	UPROPERTY(EditAnywhere)
		UUserWidget* MinimapUI;
	
	
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> TimeClass;
	UPROPERTY(EditAnywhere)
		UUserWidget* TimeUI;
	UPROPERTY(EditAnywhere)
		UTimerUserWidget* TimeText;
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> ScoreClass;
	UPROPERTY(EditAnywhere)
		UUserWidget* ScoreUI;
	UPROPERTY(EditAnywhere)
		UScoreUserWidget* ScoreText;




public:
	UUserWidget* GetTimerHandle() { return TimeUI; }


	
};
