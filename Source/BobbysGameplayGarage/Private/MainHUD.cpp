// Fill out your copyright notice in the Description page of Project Settings.

#include "MainHUD.h"
#include "Engine.h" 
#include <Attribute.h>
#include "Widgets/SWeakWidget.h" 
#include "SMyGenericCompoundWidget.h"

AMainHUD::AMainHUD()
{
		
	//TODO: Look into this construction function

	// Create a SMyUIWidget on heap, our MyUIWidget shared pointer provides handle to object
	MyUIWidget = SNew(SMyGenericCompoundWidget).HUD(this);
	// MyUIWidget = SNew(SMyGenericCompoundWidget).OwnerHUD(this);

	// Pass our viewport a weak ptr to our widget
	// View port's weak ptr will not give Viewport ownership of Widget
	if (GEngine != NULL) 
		GEngine->GameViewport->AddViewportWidgetContent(
			SNew(SWeakWidget)
			.PossiblyNullContent(MyUIWidget.ToSharedRef())
		);


	MyUIWidget->SetVisibility(EVisibility::Visible);
}
// TODO: Test polling from a widget, more performant solution according to UE4
void AMainHUD::getPlayerHealth() {

	const FString pHealth = " " + PLAYER_HEALTH;

	if (GEngine != NULL) 
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, pHealth);
}

FReply AMainHUD::ButtonClick() {

	if (GEngine != NULL)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("HUD: You clicked a button!"));

	// prevents the event from bubbling up the parent widget
	return FReply::Handled();
}
