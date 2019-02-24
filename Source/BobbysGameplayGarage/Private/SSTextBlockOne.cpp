// Fill out your copyright notice in the Description page of Project Settings.

#include "SSTextBlockOne.h"
#include "SlateOptMacros.h"
#include <CoreStyle.h>
#include <SBoxPanel.h>
#include <SOverlay.h>
#include <DeclarativeSyntaxSupport.h>
#include <SBorder.h>

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSTextBlockOne::Construct(const FArguments& InArgs)
{

	Data = InArgs._Data;
	
	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot().VAlign(VAlign_Top).HAlign(HAlign_Left).Padding(10)
		[

			SNew(SBorder)
			.Padding(FMargin(3)).BorderImage(&brush)
		[

			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth()
		[
				SNew(STextBlock).Text(this, &SSTextBlockOne::getText)
		]
		]
		]
		];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FText SSTextBlockOne::getText() const {
	return HealthTitle;
}
