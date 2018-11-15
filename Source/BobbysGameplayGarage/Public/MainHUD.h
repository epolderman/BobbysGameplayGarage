// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include <DeclarativeSyntaxSupport.h>
#include "MainHUD.generated.h"

class SHealthController;
DECLARE_DELEGATE_RetVal(FReply, hudFunctionCall)

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

	int32 getPlayerHealth() const;
	FReply ButtonClick();

protected:

	/** Cross hair asset pointer */
	// UTexture2D* CrosshairTex;

	// HUD owns widget, adds to refcount keeping it alive
	TSharedPtr<SHealthController> MyUIWidget;

private:
	
};
