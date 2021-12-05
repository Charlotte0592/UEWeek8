// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponActualMaster.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/PointLightComponent.h"

// Sets default values
AWeaponActualMaster::AWeaponActualMaster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SceneComponent->SetupAttachment(RootComponent);
	RootComponent = SceneComponent;


	WeaponActualSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponActualSkeletalMesh"));
	WeaponActualSkeletalMesh->SetupAttachment(SceneComponent);

	LaserSightMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaserSightMesh"));
	LaserSightMesh->SetupAttachment(WeaponActualSkeletalMesh);

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	PointLight->SetupAttachment(LaserSightMesh);
	
}

// Called when the game starts or when spawned
void AWeaponActualMaster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponActualMaster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

