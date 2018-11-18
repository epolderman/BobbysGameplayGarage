// Fill out your copyright notice in the Description page of Project Settings.

#include "SHealthController.h"
#include "SlateOptMacros.h"
#include "Engine.h"
#include "MainHUD.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHealthController::Construct(const FArguments& InArgs)
{
	// make horizontal box, fill according to health, rotate box around the up vector
	// we want to simulate a DOOM FPS UI

	HUD = InArgs._HUD;
	ChildSlot
		.VAlign(VAlign_Bottom)
		.HAlign(HAlign_Right)
		[
		SNew(SButton)
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Center)
		.OnHovered_Raw(this, &SHealthController::ButtonHovered)
		.ButtonColorAndOpacity(FSlateColor(FLinearColor(0.1f, 0.5f, 0.5f, 1.0f)))
		.Text(this->buttonLabel.FromString("Slate Button")).DesiredSizeScale(FVector2D(5.0f, 5.0f))
		.OnClicked(this, &SHealthController::ButtonClicked)
		.ToolTipText(this->buttonLabel.FromString("Tool Tip!"))
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
