// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ThirdPersonMPCharacter.generated.h"

UCLASS(config=Game)
class AThirdPersonMPCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	

public:
	AThirdPersonMPCharacter();
	/**  Ù–‘∏¥÷∆ */
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	// Character movement speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	float CurrentHealth = 100;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MaxHealth = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	bool bIsDead = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAmmoSystem* AmmoSystem;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated)
		float MoveFor;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated)
		float MoveRi;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated)
		float AxisTurn;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated)
		float LookUpAxis;
	UFUNCTION(Server, Reliable)
		void MoveForwardToServer(float Value);
	UFUNCTION(Server, Reliable)
		void MoveRightToServer(float Value);
	UFUNCTION(Server, Reliable)
		void AxisTurnToServer(float Value);
	UFUNCTION(Server, Reliable)
		void LookUpToServer(float Value);

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	void Turn(float Value);

	void LookUp(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

