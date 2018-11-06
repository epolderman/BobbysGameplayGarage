// Fill out your copyright notice in the Description page of Project Settings.

#include "SMyGenericCompoundWidget.h"
#include "SlateOptMacros.h"
#include "Engine.h"
#include "MainHUD.h"

// NOTE: onClicked takes (ptr to widget, delegate (pointer to method) 

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMyGenericCompoundWidget::Construct(const FArguments& InArgs)
{
	// pass in our arguments
	HUD = InArgs._HUD;

	ChildSlot
	.VAlign(VAlign_Bottom)
	.HAlign(HAlign_Right)
					[
					SNew(SButton)
					.VAlign(VAlign_Center)
					.HAlign(HAlign_Center)
					.OnHovered_Raw(this, &SMyGenericCompoundWidget::ButtonHovered)
					.ButtonColorAndOpacity(FSlateColor(FLinearColor(0.1f, 0.5f, 0.5f, 1.0f)))
					.Text(this->buttonLabel.FromString("Slate Button")).DesiredSizeScale(FVector2D(5.0f, 5.0f))
					.OnClicked(this, &SMyGenericCompoundWidget::ButtonClicked)
					.ToolTipText(this->buttonLabel.FromString("Tool Tip!"))
					];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SMyGenericCompoundWidget::ButtonClicked() {

	if (HUD != nullptr)
		HUD->ButtonClick();

	// OnClicked.ExecuteIfBound();

	return FReply::Handled();
}
// TODO: Add functionality to style differently on hover
void SMyGenericCompoundWidget::ButtonHovered() {

	if (GEngine != NULL) 
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Hovering"));

}