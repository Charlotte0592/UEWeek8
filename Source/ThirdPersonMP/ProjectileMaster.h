// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileMaster.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;

UCLASS()
class THIRDPERSONMP_API AProjectileMaster : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(Category = Projectile, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		USphereComponent* Sphere;
	UPROPERTY(Category = Projectile, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(Category = Projectile, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UParticleSystemComponent* ParticleSystem;

public:	
	// Sets default values for this actor's properties
	AProjectileMaster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
