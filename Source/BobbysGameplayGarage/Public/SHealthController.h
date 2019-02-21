// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SlateGameResources.h"
class AMainHUD;

// delegate with no param / return value
DECLARE_DELEGATE(FHealthClick)

class BOBBYSGAMEPLAYGARAGE_API SHealthController : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SHealthController)
	{}
	SLATE_ARGUMENT(class AMainHUD*, HUD)
	SLATE_EVENT(FHealthClick, OnClicked)
	SLATE_END_ARGS()
public:
	void Construct(const FArguments& InArgs);
	FReply Log();
private:
	TWeakObjectPtr<class AMainHUD> HUD;
	FText buttonLabel;
	FSlateColorBrush brush = FSlateColorBrush(FLinearColor::Yellow);
	// slate data
	FHealthClick OnClicked;
	FReply OnButtonClick();
};