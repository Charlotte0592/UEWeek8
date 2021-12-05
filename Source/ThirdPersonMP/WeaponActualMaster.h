// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponActualMaster.generated.h"

class USceneComponent;
class USkeletalMeshComponent;
class UStaticMeshComponent;
class UPointLightComponent;

UCLASS()
class THIRDPERSONMP_API AWeaponActualMaster : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(Category = Weapon, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USceneComponent* SceneComponent;

	UPROPERTY(Category = Weapon, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* WeaponActualSkeletalMesh;
	
	UPROPERTY(Category = Weapon, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* LaserSightMesh;
	
	UPROPERTY(Category = Weapon, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPointLightComponent* PointLight;

public:	
	// Sets default values for this actor's properties
	AWeaponActualMaster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
