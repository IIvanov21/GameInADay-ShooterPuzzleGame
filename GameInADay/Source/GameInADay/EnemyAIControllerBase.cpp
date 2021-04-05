// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIControllerBase.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/TargetPoint.h"
#include "GameFramework/Actor.h"
#include "BehaviorTree/BlackboardComponent.h"
void AEnemyAIControllerBase::BeginPlay()
{
	Super::BeginPlay();
	AIPawn = GetPawn();
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (EnemyBehaviorTree != nullptr) RunBehaviorTree(EnemyBehaviorTree);
	GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), AIPawn->GetActorLocation());
	

}

// Called every frame
void AEnemyAIControllerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


