// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "MainHUD.h"


class BOBBYSGAMEPLAYGARAGE_API SMyGenericCompoundWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMyGenericCompoundWidget)
	{}

	// SLATE_EVENT(hudFunctionCall, OnClicked)

	// slate arguments (type, name of type) => passing args to widgets constructing function
	SLATE_ARGUMENT(class AMainHUD*, hudController)
	// SLATE_ARGUMENT(hudFunctionCall, OnClicked)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	FReply ButtonClicked();

	void ButtonHovered();
private:
	TWeakObjectPtr<class AMainHUD> HUD;

	FText buttonLabel;

	hudFunctionCall OnClicked;
};
