// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class BOBBYSGAMEPLAYGARAGE_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	// Default is 3rd Person
	bool bIsFirstPersonPerspectiveEnabled;

	// In 3rd Person Perspective
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
		float TrailingCameraDistance = 300.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Camera")
		float BaseTurnRate = 45.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Camera")
		float BaseLookUpRate = 45.0f;

protected:

	void MoveForward(float Value);

	void MoveRight(float Value);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	void ToggleFirstPersonPerspective();

	const FRotator getCharacterRotation();

public:	
	AMainCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Camera 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class USpringArmComponent* CameraBoom;

	// Trailing Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class UCameraComponent* TrailingCamera;
};
