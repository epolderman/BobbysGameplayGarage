#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include <SlateColorBrush.h>

/*

	Compound Widgets - widgets with a fixed number of explicitly named child slots. 
	e.g. SButton has one slot called Content which contains any widgets inside the button.

	Has their own OnPaint call. Responsible for their own drawing. 

*/

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
	// delegate object
	FHealthClick OnClicked;
	// function to run the delegate
	FReply OnButtonClick();
	FSlateColorBrush brush = FSlateColorBrush(FLinearColor::Yellow);
};
