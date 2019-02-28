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

	OnClicked.BindUObject(this, &AMainHUD::DisplayPlayerHealth);
	ASAPButton = SNew(SSButtonOne).OnClicked(OnClicked);
	ASAPTextBlock = SNew(SSTextBlockOne);
	OnHealthChange.AddUObject(this, &AMainHUD::printHealth);


	if (GEngine != nullptr)
	{
	

		GEngine->GameViewport->AddViewportWidgetContent(
			ASAPTextBlock.ToSharedRef()
		);

		GEngine->GameViewport->AddViewportWidgetContent(
			ASAPButton.ToSharedRef()
		);

	/*	GEngine->GameViewport->AddViewportWidgetContent(
			ASAPText.ToSharedRef()
		);*/
	}
}


void AMainHUD::DisplayPlayerHealth() {

	UE_LOG(LogClass, Log, TEXT("AMAINHUD::DisplayPlayerHealth"));

	const AMainCharacter * character = Cast<AMainCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (character != nullptr) {
		UE_LOG(LogClass, Log, TEXT("PlayerHealth: %f"), character->getHealth());
		character->OnHealthUpdated.Broadcast(5);
	}
	else {
		UE_LOG(LogClass, Log, TEXT("Character Instance is null"));
	}

}

FText AMainHUD::getText() const {
	return FText::FromString("Player Health");;
}

void AMainHUD::printHealth(float health)  {
	UE_LOG(LogClass, Log, TEXT("PlayerHealth: %f"), health);
}


