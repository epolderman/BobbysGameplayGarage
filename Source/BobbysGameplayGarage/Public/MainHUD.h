// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class BOBBYSGAMEPLAYGARAGE_API AMainHUD : public AHUD
{
	GENERATED_BODY()

protected:

	/** Cross hair asset pointer */
	// UTexture2D* CrosshairTex;

public:

	AMainHUD();

	/** Primary draw call for the HUD */
	// virtual void DrawHUD() override;
};
