// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeActor.generated.h"
class AGameInADayGameModeBase;
class UTimerUserWidget;
class APlayerControllerBase;
UCLASS()
class GAMEINADAY_API ATimeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	UPROPERTY()
		AGameInADayGameModeBase* GameModeRef;
	UPROPERTY(EditAnywhere)
		float TimeCountDown = 600.0f;
	UPROPERTY(EditAnywhere)
		APlayerControllerBase* PlayerController;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
