// Copyright Epic Games, Inc. All Rights Reserved.


#include "GameInADayGameModeBase.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void AGameInADayGameModeBase::TimeUp()
{
	GameOver(false);
}

void AGameInADayGameModeBase::StartGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Game started!"));
}

void AGameInADayGameModeBase::EndGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Player Wins!"));
	//UGameplayStatics::OpenLevel(GetWorld(), "EndLevel");

}
void AGameInADayGameModeBase::GameOver(bool IsFinished)
{
	if (IsFinished)UE_LOG(LogTemp, Warning, TEXT("Game lost!"));
	UGameplayStatics::OpenLevel(GetWorld(), "GameOver");

}

void AGameInADayGameModeBase::BeginPlay()
{
	StartGame();
	
	GetWorld()->GetTimerManager().SetTimer(EndGameTimer, this, &AGameInADayGameModeBase::TimeUp, GameDuration, false);

}

FString AGameInADayGameModeBase::GetTime()
{
	return EndGameTimer.ToString();
}
