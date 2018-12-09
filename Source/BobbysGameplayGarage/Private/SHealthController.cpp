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

	FSlateFontInfo LargeLayoutFont = FCoreStyle::GetDefaultFontStyle("Regular", 16);
	FSlateFontInfo SmallLayoutFont = FCoreStyle::GetDefaultFontStyle("Regular", 10);

	ChildSlot
		[
		SNew(SScrollBox)
		+ SScrollBox::Slot().Padding(10, 5).VAlign(VAlign_Bottom).HAlign(HAlign_Right)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.AutoWidth()
		[
			SNew(SButton).Text(LOCTEXT("ExampleLayout-TextLabel01", "Default.\n Slot is auto-sized."))
		]
	+ SHorizontalBox::Slot()
		.AutoWidth()
		[
			SNew(SButton).Text(LOCTEXT("ExampleLayout-TextLabel02", "Slots are packed tightly."))
		]
	+ SHorizontalBox::Slot()
		.AutoWidth()
		[
			SNew(SButton).Text(LOCTEXT("ExampleLayout-TextLabel03", "Alignment within the slot\n does not matter."))
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