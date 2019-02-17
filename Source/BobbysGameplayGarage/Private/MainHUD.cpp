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

	if (GEngine != nullptr)
		GEngine->GameViewport->AddViewportWidgetContent(
			MyUIWidget.ToSharedRef()
		);

	MyUIWidget->SetVisibility(EVisibility::Visible);
}

float AMainHUD::OnGetHPPercent() const {
	const AMainCharacter * character = Cast<AMainCharacter>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetCharacter());
	if (character != nullptr) 
	return character->getPlayerHealth();

	return 0.0f;
}


FString AMainHUD::getPlayerHealth() const{

	/*const AMainCharacter * character = Cast<AMainCharacter>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetCharacter());
	if (character != nullptr) {
		return FString::SanitizeFloat(character->getPlayerHealth());
	}
	FString nonValidHealth = FString::SanitizeFloat(0.0f);
	return nonValidHealth;*/
	return FString("hello");
}

FReply AMainHUD::ButtonClick() {
	
	//const AMainCharacter * character = Cast<AMainCharacter>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	//if (character != nullptr) {
	//	FString TheFloatStr = FString::SanitizeFloat(character->getPlayerHealth());
	//	UE_LOG(LogClass, Log, TEXT("Player Health: %s"), *TheFloatStr);
	//}
	// prevents the event from bubbling up the parent widget
	return FReply::Handled();
}

FString AMainHUD::LogCreation() const {

	auto character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	if (character != nullptr) {
		/*FString TheFloatStr = FString::SanitizeFloat(character->getPlayerHealth());*/
		UE_LOG(LogClass, Log, TEXT("We have a character instance"));
	}
	else {
		UE_LOG(LogClass, Log, TEXT("character instance in null"));
	}
	return FString("LogCreation()");
}
