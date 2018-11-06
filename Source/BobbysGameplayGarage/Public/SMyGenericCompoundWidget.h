// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "MainHUD.h"


class BOBBYSGAMEPLAYGARAGE_API SMyGenericCompoundWidget : public SCompoundWidget
{

	SLATE_BEGIN_ARGS(SMyGenericCompoundWidget){}
	SLATE_ARGUMENT(class AMainHUD*, HUD)
	SLATE_END_ARGS()

public:
	void Construct(const FArguments& InArgs);

	FReply ButtonClicked();

	void ButtonHovered();
private:
	TWeakObjectPtr<class AMainHUD> HUD;

	FText buttonLabel;
};
