// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameInADayGameModeBase.generated.h"
/**
 * 
 */

UCLASS()
class GAMEINADAY_API AGameInADayGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
private:
	UPROPERTY()
		FTimerHandle EndGameTimer;
	UPROPERTY()
		float GameDuration = 600.0f;
	UFUNCTION()
		void TimeUp();
	UFUNCTION()
		void StartGame();
	UFUNCTION()
		void EndGame();
	UFUNCTION()
		void GameOver(bool IsFinished);

	
public:
	UFUNCTION()
		FString GetTime();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
