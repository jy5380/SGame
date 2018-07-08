// Fill out your copyright notice in the Description page of Project Settings.

#include "SGame.h"
#include "SGameMessages.h"
#include "SGCheatManager.h"



USGCheatManager::USGCheatManager()
{	
	MessageEndPoint = FMessageEndpoint::Builder("CheatManagerMessageEP");
}

void USGCheatManager::StartGame()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Force Start Game"));

	check(MessageEndPoint.IsValid());

	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_RondBegin;

	MessageEndPoint->Publish(Message, EMessageScope::Process);
}
