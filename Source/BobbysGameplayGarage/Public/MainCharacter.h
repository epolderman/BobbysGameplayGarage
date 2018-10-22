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
	/*UPROPERTY(BlueprintReadOnly, Category = "Gameplay")*/

	// default is Third Person
	bool bIsFirstPersonPerspectiveEnabled;

	const float CAMERA_BOOM_DISTANCE = 300.0f;
protected:

	void MoveForward(float Value);

	void MoveRight(float Value);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	void EnableFirstPersonPerspective();

public:	
	// Constructor
	AMainCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Camera 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		class USpringArmComponent* CameraBoom;

	// Trailing Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		class UCameraComponent* TrailingCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;
};
