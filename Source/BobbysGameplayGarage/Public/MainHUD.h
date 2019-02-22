// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include <DeclarativeSyntaxSupport.h>
#include <SlateDelegates.h>
#include "SHealthController.h"
#include "SSButtonOne.h"
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

	// UFUNCTION()
	FReply LogCreation() const;
	void Log();
	//UFUNCTION()
	//void pollHealth(float playerHealth);

protected:

	/** Cross hair asset pointer */
	// UTexture2D* CrosshairTex;

	// HUD owns widget, adds to refcount keeping it alive
	TSharedPtr<SHealthController> MyUIWidget;
	FHealthClick OnClicked;
	TSharedPtr<SSButtonOne> ASAPButton;

private:
	
};
