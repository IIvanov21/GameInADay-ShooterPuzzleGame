// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuzzleActor.generated.h"
class UStaticMeshComponent;
UCLASS()
class GAMEINADAY_API APuzzleActor : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* PuzzleMesh;
public:	
	// Sets default values for this actor's properties
	APuzzleActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Rotate();
};
