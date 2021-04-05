// Fill out your copyright notice in the Description page of Project Settings.


#include "DestructibleActor.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ADestructibleActor::ADestructibleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DesctructableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Desctructable Mesh"));
	DesctructableMesh->SetupAttachment(RootComponent);
	DesctructableMesh->SetSimulatePhysics(true);

	ForceComp = CreateDefaultSubobject<URadialForceComponent>(TEXT("Force Component"));
	ForceComp->SetupAttachment(DesctructableMesh);
}

// Called when the game starts or when spawned
void ADestructibleActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestructibleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ADestructibleActor::Explode()
{
	DesctructableMesh->AddForce(GetActorUpVector() * ForceAmount * DesctructableMesh->GetMass());
	DesctructableMesh->AddTorqueInRadians(FVector(0.0f, 0.0f, 5.0f) * ForceAmount * DesctructableMesh->GetMass());
	ForceComp->FireImpulse();
	Destroy();
}