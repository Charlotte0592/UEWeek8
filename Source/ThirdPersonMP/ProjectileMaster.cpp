// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileMaster.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AProjectileMaster::AProjectileMaster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(RootComponent);
	RootComponent = Sphere;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleSystem->SetupAttachment(Sphere);
}

// Called when the game starts or when spawned
void AProjectileMaster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileMaster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
