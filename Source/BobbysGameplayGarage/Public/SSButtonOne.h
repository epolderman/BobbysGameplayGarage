// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include <SlateColorBrush.h>

// delegate with no param / return value
DECLARE_DELEGATE(FHealthClick)

class BOBBYSGAMEPLAYGARAGE_API SSButtonOne : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSButtonOne)
	{}
	SLATE_EVENT(FHealthClick, OnClicked)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	FHealthClick OnClicked;
	FReply OnButtonClick();
	FSlateColorBrush brush = FSlateColorBrush(FLinearColor::Yellow);
};
