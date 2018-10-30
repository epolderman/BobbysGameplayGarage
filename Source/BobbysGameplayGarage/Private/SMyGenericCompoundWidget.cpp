// Fill out your copyright notice in the Description page of Project Settings.

#include "SMyGenericCompoundWidget.h"
#include "SlateOptMacros.h"
#include "Engine.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMyGenericCompoundWidget::Construct(const FArguments& InArgs)
{
	// pass in our arguments
	HUD = InArgs._hudController;


	// onClicked takes (ptr to widget, delegate(pointer to method) 
	ChildSlot
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Center)
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
	if (GEngine != NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You clicked a button!"));
	}

	// prevents the event from bubbling up the parent widget
	return FReply::Handled();
}

void SMyGenericCompoundWidget::ButtonHovered() {
	if (GEngine != NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Hovering"));
	}
}