// Fill out your copyright notice in the Description page of Project Settings.

#include "SSButtonOne.h"
#include "SlateOptMacros.h"
#include <DeclarativeSyntaxSupport.h>
#include <CoreStyle.h>
#include <SBoxPanel.h>
#include <SOverlay.h>


#define LOCTEXT_NAMESPACE "BBGameplayG"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSButtonOne::Construct(const FArguments& InArgs)
{

	OnClicked = InArgs._OnClicked;

	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot().VAlign(VAlign_Bottom).HAlign(HAlign_Right).Padding(10)
		[

			SNew(SBorder)
			.Padding(FMargin(3)).BorderImage(&brush)
		[

			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth()
		[
			SNew(SButton).ButtonStyle(FCoreStyle::Get(), "NoBorder").Text(LOCTEXT("One", "Delegate Click")).OnClicked_Raw(this, &SSButtonOne::OnButtonClick)
		]

		]
		]
		];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SSButtonOne::OnButtonClick()
{
	UE_LOG(LogClass, Log, TEXT("SSButtonOne::OnButtonClick"));

	if (OnClicked.IsBound())
		OnClicked.Execute();
	else
		UE_LOG(LogClass, Log, TEXT("NOT Broadcasting Delegate"));

	return FReply::Handled();
}


#undef LOCTEXT_NAMESPACE