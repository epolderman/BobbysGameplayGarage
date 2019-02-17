// Fill out your copyright notice in the Description page of Project Settings.

#include "SHealthController.h"
#include "SlateOptMacros.h"
#include "Engine.h"
#include "MainHUD.h"
#include "GameFramework/PlayerController.h"
#include "MainCharacter.h"
#include <Attribute.h>
#include "Engine/World.h"

#define LOCTEXT_NAMESPACE "BBGameplayG"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHealthController::Construct(const FArguments& InArgs)
{
	// make horizontal box, fill according to health, rotate box around the up vector
	// we want to simulate a DOOM FPS UI

	HUD = InArgs._HUD;
	const FVector2D HeadingShadowOffset(2, 2);


	// is this how we set up fonts?
	FSlateFontInfo LargeLayoutFont = FCoreStyle::GetDefaultFontStyle("Regular", 16);
	FSlateFontInfo SmallLayoutFont = FCoreStyle::GetDefaultFontStyle("Regular", 10);

	UE_LOG(LogClass, Log, TEXT("Constructing SHealthController"));

	// is this how we set up styles?
	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot().VAlign(VAlign_Bottom).HAlign(HAlign_Right).Padding(10)
		[
		
			SNew(SBorder)
			.Padding(FMargin(3)).BorderImage(&brush)
		[
		
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth()
		[
			SNew(SButton).ButtonStyle(FCoreStyle::Get(), "NoBorder").Text(LOCTEXT("One", "Default.\n Health Values"))
		]
			+ SHorizontalBox::Slot().AutoWidth()
		[
		
			SNew(SButton).Text(LOCTEXT("two", " Content, Content, Content")).OnClicked_Raw(this, &SHealthController::Log)
		]
			+ SHorizontalBox::Slot().AutoWidth()
		[
			SNew(SButton).Text(LOCTEXT("Three", " Content, Content, Content"))
		]
		]
		]
		];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

/*
Every class derived from AActor can use GetWorld() to access the World it is currently spawned in: https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/GameFramework/AActor/GetWorld/index.html

including APlayerController, AHUD, AGameMode, AGameState, and so on.

You can call GetWorld() in UGameViewport to get the World it's related to at the moment, you can call GetWorld() in UGameInstance.
*/

FReply SHealthController::Log() {

	if (GEngine != nullptr) {
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GEngine->GetWorld(), AActor::StaticClass(), FoundActors);
		/*const AMainCharacter * character = Cast<AMainCharacter>(UGameplayStatics::GetPlayerCharacter(GEngine->GetWorld(), 0));*/
		APlayerController * MyPc = UGameplayStatics::GetPlayerController(GEngine->GetWorld(), 0);
		
		//UE_LOG(LogClass, Log, TEXT("Name: %i"), FoundActors.Num());
		//for (int32 i = 0; i < FoundActors.Num(); i++) {
		//UE_LOG(LogClass, Log, TEXT("Name: %s"), *FoundActors[i]->GetName());
		//}



		if (MyPc != nullptr) {
			/*FString TheFloatStr = FString::SanitizeFloat(character->getPlayerHealth());*/
			UE_LOG(LogClass, Log, TEXT("We have a character instance"));
			// character->PlayerHealth.AddDynamic(this, &AMainHUD::pollHealth);
		}
		else {
			UE_LOG(LogClass, Log, TEXT("character instance in null"));
		}
	}
	else {
		UE_LOG(LogClass, Log, TEXT("gengine instance in null"));
	}
	

	return FReply::Handled();
}


#undef LOCTEXT_NAMESPACE