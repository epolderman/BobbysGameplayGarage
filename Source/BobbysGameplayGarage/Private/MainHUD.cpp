// Fill out your copyright notice in the Description page of Project Settings.

#include "MainHUD.h"
#include "Engine.h" 
#include <Attribute.h>
#include "Widgets/SWeakWidget.h" 
#include "SHealthController.h"
#include "MainCharacter.h"
#include "GameFramework/PlayerController.h"

/*
		--HUD--
		Every character instance has their own instance of the HUD.
		Draws to their individual viewport. 


		Questions: 
		Has access to GEngine instance?


		Current Feature: 
		Reads model data (character health)
*/

AMainHUD::AMainHUD()
{
		
	UE_LOG(LogClass, Log, TEXT("Constructing HUD"));

	// Create a SMyGenericCompoundWidget on heap, 
	// our MyUIWidget shared pointer provides handle to object
	// MyUIWidget = SNew(SHealthController).HUD(this);
	OnClicked.BindUObject(this, &AMainHUD::DisplayPlayerHealth);
	ASAPButton = SNew(SSButtonOne).OnClicked(OnClicked);

	if (GEngine != nullptr)
		GEngine->GameViewport->AddViewportWidgetContent(
			ASAPButton.ToSharedRef()
		);
}


void AMainHUD::DisplayPlayerHealth() {

	UE_LOG(LogClass, Log, TEXT("AMAINHUD::DisplayPlayerHealth"));

	const AMainCharacter * character = Cast<AMainCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (character != nullptr) {
		UE_LOG(LogClass, Log, TEXT("PlayerHealth: %f"), character->getHealth());
	}
	else {
		UE_LOG(LogClass, Log, TEXT("Character Instance is null"));
	}

}
