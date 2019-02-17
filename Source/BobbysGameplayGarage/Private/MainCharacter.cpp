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
	UE_LOG(LogClass, Log, TEXT("Constructing AMainCharacter"));

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	// Character moves in the direction of input
	GetCharacterMovement()->bOrientRotationToMovement = true; 

	// matrix of only affecting the y
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); 
	GetCharacterMovement()->JumpZVelocity = 750.0f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = TrailingCameraDistance; 
	CameraBoom->bUsePawnControlRotation = true;

	// Create a trailing camera
	TrailingCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TrailingCamera"));
	TrailingCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); 
	TrailingCamera->bUsePawnControlRotation = false; 
	
	iPlayerHealth = 50;
	bIsFirstPersonPerspectiveEnabled = false;
	// UE_LOG(LogClass, Log, TEXT("Hello There!!...!"));
}

void AMainCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (this->TrailingCamera != nullptr) {
		TrailingCamera->RelativeLocation = TrailingCameraLocation;
	}
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// is the parent class constructor super needed?
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Game Play Bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("ToFirstPerson", IE_Pressed, this, &AMainCharacter::ToggleFirstPersonPerspective);

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
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMainCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

// TODO: this needs to be smooth instead of instant
void AMainCharacter::ToggleFirstPersonPerspective()
{
	if (TrailingCamera && CameraBoom != nullptr) {

		if (!bIsFirstPersonPerspectiveEnabled) {
			CameraBoom->TargetArmLength = 0.0f;
			// Position the camera
			TrailingCamera->RelativeLocation = FVector(0, 10.0f, BaseEyeHeight); 
			bIsFirstPersonPerspectiveEnabled = true;
			return;
		}

		// The camera follows at this distance behind the character
		CameraBoom->TargetArmLength = TrailingCameraDistance; 	
		TrailingCamera->RelativeLocation = TrailingCameraLocation;
		bIsFirstPersonPerspectiveEnabled = false;
	}
}

const FRotator AMainCharacter::getCharacterRotation() {
	const FRotator Rotation = Controller->GetControlRotation();
	return FRotator(0, Rotation.Yaw, 0);
}

void AMainCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// get forward vector +X is forward, -X is back
		const FVector Direction = FRotationMatrix(this->getCharacterRotation()).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}

	// test on delegates
	/*this->iPlayerHealth = this->iPlayerHealth - 2.0f;
	PlayerHealth.Broadcast(this->iPlayerHealth);*/

}

void AMainCharacter::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// get right vector which would be Y (ue4: left hand coordinate system)
		// +Y is right, -Y is left
		const FVector Direction = FRotationMatrix(this->getCharacterRotation()).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}
