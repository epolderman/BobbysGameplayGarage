#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include <DeclarativeSyntaxSupport.h>
#include <SlateDelegates.h>
#include "SHealthController.h"
#include "SSButtonOne.h"
#include "SSTextBlockOne.h"
#include <STextBlock.h>
#include <MainCharacter.h>
#include "MainHUD.generated.h"


UCLASS()
class BOBBYSGAMEPLAYGARAGE_API AMainHUD : public AHUD
{

	GENERATED_BODY()
public:

	AMainHUD();

	/** Primary draw call for the HUD */
	// virtual void DrawHUD() override;

	// ++ Called as soon as game starts, create SCompoundWidget and give Viewport access
	// void BeginPlay();

	void DisplayPlayerHealth();
	FText getText() const;

	UFUNCTION()
	void printHealth(float health);
protected:

	/** Cross hair asset pointer */
	// UTexture2D* CrosshairTex;

	// HUD owns widget, adds to refcount keeping it alive
	// TSharedPtr<SHealthController> MyUIWidget;
	FHealthClick OnClicked;
	TSharedPtr<SSButtonOne> ASAPButton;
	TSharedPtr<SSTextBlockOne> ASAPTextBlock;
	TSharedPtr<STextBlock> ASAPText;
	FChangedHealthEvent OnHealthChange;


private:
	
};
