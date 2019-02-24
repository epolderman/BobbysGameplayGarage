// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SlateOptMacros.h"
#include <SlateColorBrush.h>
#include <STextBlock.h>


class BOBBYSGAMEPLAYGARAGE_API SSTextBlockOne : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSTextBlockOne)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	FText HealthTitle = FText::FromString("Player Health:");
	FText getText() const;
	FSlateColorBrush brush = FSlateColorBrush(FLinearColor::Blue);
};
