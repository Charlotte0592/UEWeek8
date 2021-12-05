// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponPickupMaster.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AWeaponPickupMaster::AWeaponPickupMaster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root_C = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	Root_C->SetupAttachment(RootComponent);
	RootComponent = Root_C;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetupAttachment(Root_C);

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(BoxComponent);
}

// Called when the game starts or when spawned
void AWeaponPickupMaster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponPickupMaster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

