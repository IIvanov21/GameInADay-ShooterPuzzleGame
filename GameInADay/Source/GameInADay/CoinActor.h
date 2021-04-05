// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoinActor.generated.h"
class APlayerControllerBase;
UCLASS()
class GAMEINADAY_API ACoinActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoinActor();
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* CoinMesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AddPoints();
	UPROPERTY(EditAnywhere)
		APlayerControllerBase* PlayerController;
};
