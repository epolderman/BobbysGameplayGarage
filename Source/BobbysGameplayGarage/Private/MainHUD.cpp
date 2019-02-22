// Fill out your copyright notice in the Description page of Project Settings.

#include "MainHUD.h"
#include "Engine.h" 
#include <Attribute.h>
#include "Widgets/SWeakWidget.h" 
#include "SHealthController.h"
#include "MainCharacter.h"
#include "GameFramework/PlayerController.h"



AMainHUD::AMainHUD()
{
		
	UE_LOG(LogClass, Log, TEXT("Constructing HUD"));

	// Create a SMyGenericCompoundWidget on heap, 
	// our MyUIWidget shared pointer provides handle to object
	MyUIWidget = SNew(SHealthController).HUD(this);
	OnClicked.BindUObject(this, &AMainHUD::Log);
	ASAPButton = SNew(SSButtonOne).OnClicked(OnClicked);

	if (GEngine != nullptr)
		GEngine->GameViewport->AddViewportWidgetContent(
			ASAPButton.ToSharedRef()
		);

	// MyUIWidget->SetVisibility(EVisibility::Visible);

	
}


FReply AMainHUD::LogCreation() const {

	auto character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	if (character != nullptr) {
		UE_LOG(LogClass, Log, TEXT("We have a character instance"));
		// character->PlayerHealth.AddDynamic(this, &AMainHUD::pollHealth);
	}
	else {
		UE_LOG(LogClass, Log, TEXT("character instance in null"));
	}

	return FReply::Handled();
}

void AMainHUD::Log() {
	UE_LOG(LogClass, Log, TEXT("AMAINHUD::Log"));
}
