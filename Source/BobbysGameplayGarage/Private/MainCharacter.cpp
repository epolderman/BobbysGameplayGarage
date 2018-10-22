// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"



// Sets default values
AMainCharacter::AMainCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.0f;
	BaseLookUpRate = 45.0f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 1000.0f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = CAMERA_BOOM_DISTANCE; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a trailing camera
	TrailingCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TrailingCamera"));
	TrailingCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); 
	TrailingCamera->bUsePawnControlRotation = false; 

	bIsFirstPersonPerspectiveEnabled = false;
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Game Play Bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("ToFirstPerson", IE_Pressed, this, &AMainCharacter::ToggleFirstPersonPerspective);
	// PlayerInputComponent->BindAction("ToFirstPerson", IE_Pressed, this, &ACharacter::Jump);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);

	// Mouse (Turn uses Delta)
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	// Controller Analog Stick
	PlayerInputComponent->BindAxis("TurnRate", this, &AMainCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMainCharacter::LookUpAtRate);
}

void AMainCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMainCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

// WIP, fix this
void AMainCharacter::ToggleFirstPersonPerspective()
{
	if (TrailingCamera && CameraBoom != nullptr) {

		if (!bIsFirstPersonPerspectiveEnabled) {
			CameraBoom->TargetArmLength = 0.0f; // The camera follows at this distance behind the character	
			TrailingCamera->RelativeLocation = FVector(0, 0, BaseEyeHeight); // Position the camera
			bIsFirstPersonPerspectiveEnabled = true;
			// UE_LOG(LogClass, Log, TEXT("EnabledFirstPersonPers %s"), TrailingCamera->GetSocketLocation().ToString());
			return;
		}

		CameraBoom->TargetArmLength = CAMERA_BOOM_DISTANCE; // The camera follows at this distance behind the character	
		// TrailingCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
		bIsFirstPersonPerspectiveEnabled = false;
	}
}

void AMainCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// UE_LOG(LogClass, Log, TEXT("Move Forward Triggered  %i"), Value);

		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AMainCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}


