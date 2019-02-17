// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SlateGameResources.h"
class AMainHUD;


class BOBBYSGAMEPLAYGARAGE_API SHealthController : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SHealthController)
	{}
	SLATE_ARGUMENT(class AMainHUD*, HUD)
	//SLATE_EVENT(FOnClicked, OnClicked)
	SLATE_END_ARGS()
public:
	void Construct(const FArguments& InArgs);
	FReply Log();
private:
	TWeakObjectPtr<class AMainHUD> HUD;
	FText buttonLabel;
	FSlateColorBrush brush = FSlateColorBrush(FLinearColor::Yellow);
};