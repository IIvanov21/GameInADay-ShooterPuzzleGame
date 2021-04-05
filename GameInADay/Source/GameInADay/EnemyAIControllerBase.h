// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class GAMEINADAY_API AEnemyAIControllerBase : public AAIController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	APawn* AIPawn;
	APawn* PlayerPawn;
	UPROPERTY(EditAnywhere)
		UBehaviorTree* EnemyBehaviorTree;
	 

};
