// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponPickupMaster.generated.h"

class USceneComponent;
class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class THIRDPERSONMP_API AWeaponPickupMaster : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = true))
	USceneComponent* Root_C;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* BoxComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* WeaponMesh;


public:	
	// Sets default values for this actor's properties
	AWeaponPickupMaster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
