// Fill out your copyright notice in the Description page of Project Settings.

#include "MainHUD.h"
#include "Engine.h" 
#include <Attribute.h>
#include "Widgets/SWeakWidget.h" 
#include "SHealthController.h"

AMainHUD::AMainHUD()
{
		
	//TODO: Look into this construction function

	// Create a SMyGenericCompoundWidget on heap, 
	// our MyUIWidget shared pointer provides handle to object
	MyUIWidget = SNew(SHealthController).HUD(this);
	// MyUIWidget = SNew(SMyGenericCompoundWidget).OwnerHUD(this);

	if (GEngine != nullptr)
		GEngine->GameViewport->AddViewportWidgetContent(
			MyUIWidget.ToSharedRef()
		);


	MyUIWidget->SetVisibility(EVisibility::Visible);
}
// TODO: Test polling from a widget, more performant solution according to UE4
void AMainHUD::getPlayerHealth() {

	const FString pHealth = " " + PLAYER_HEALTH;

	if (GEngine != nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, pHealth);
}

FReply AMainHUD::ButtonClick() {

	if (GEngine != nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("HUD: You clicked a button!"));

	// prevents the event from bubbling up the parent widget
	return FReply::Handled();
}
