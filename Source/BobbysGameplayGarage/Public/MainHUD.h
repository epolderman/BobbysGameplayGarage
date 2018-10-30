// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include <DeclarativeSyntaxSupport.h>
#include "MainHUD.generated.h"

class SMyGenericCompoundWidget;

UCLASS()
class BOBBYSGAMEPLAYGARAGE_API AMainHUD : public AHUD
{
	GENERATED_BODY()
public:

	AMainHUD();

	/** Primary draw call for the HUD */
	// virtual void DrawHUD() override;

protected:

	/** Cross hair asset pointer */
	// UTexture2D* CrosshairTex;
		// ++ Reference to an SCompoundWidget, TSharedPtr adds to the refcount of MyUIWidget
	// MyUIWidget will not self-destruct as long as refcount > 0. refcount will be (refcout-1) if HUD is destroyed.
	TSharedPtr<SMyGenericCompoundWidget> MyUIWidget;

	// ++ Called as soon as game starts, create SCompoundWidget and give Viewport access
	// void BeginPlay();
	void getPlayerHealth();
	FReply handleButton();

private:
	int playerHealth = 55;
};
