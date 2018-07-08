// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/CheatManager.h"
#include "SGCheatManager.generated.h"

/**
 * 
 */
UCLASS(Within = SGamePlayerController)
class SGAME_API USGCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:
	USGCheatManager();

	UFUNCTION(exec)
	void StartGame();
	
private:
	FMessageEndpointPtr MessageEndPoint;
};
