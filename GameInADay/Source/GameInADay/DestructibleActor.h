// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DestructibleActor.generated.h"

class URadialForceComponent;

UCLASS()
class GAMEINADAY_API ADestructibleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADestructibleActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Explode();
private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* DesctructableMesh;
	UPROPERTY(EditAnywhere)
		URadialForceComponent* ForceComp;
	UPROPERTY(EditAnywhere)
		float ForceAmount = 950.0f;
	UPROPERTY(EditAnywhere)
		float TorqueAmount = 10.0f;
};
