// Fill out your copyright notice in the Description page of Project Settings.

#include "SHealthController.h"
#include "SlateOptMacros.h"
#include "Engine.h"
#include "MainHUD.h"

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
	UE_LOG(LogClass, Log, TEXT("Logging Hud: %s"), *HUD->LogCreation());

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
		
			SNew(SButton).Text(LOCTEXT("two", " Content, Content, Content"))
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

FReply SHealthController::ButtonClicked() {

	if (HUD != nullptr)
		HUD->ButtonClick();

	return FReply::Handled();
}
// TODO: Add functionality to style differently on hover
void SHealthController::ButtonHovered() {

	if (GEngine != nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Hovering"));
}

#undef LOCTEXT_NAMESPACE