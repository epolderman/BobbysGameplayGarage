// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "MainHUD.h"

/**
 * 
 */
class BOBBYSGAMEPLAYGARAGE_API SMyGenericCompoundWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMyGenericCompoundWidget)
	{}
	// slate arguments (type, name of type) => passing args to widgets constructing function
	SLATE_ARGUMENT(class AMainHUD*, hudController)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);	// action/delegate for clicking

	FReply ButtonClicked();
	// why does this have to void, and not FReply?

	void ButtonHovered();
private:
	// Pointer to our parent HUD. To make sure HUD's lifetime is controlled elsewhere, use "weak" ptr. 
	// HUD has a "strong" pointer to Widget, circular ownership would prevent/break self-destruction of HUD/widget (cause a memory leak). 
	// Is there a better way to handle this? Why must we pass the HUD as an argument to the widget?
	TWeakObjectPtr<class AMainHUD> HUD;
	FText buttonLabel;
};
