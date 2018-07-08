// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "SGame.h"
#include "SGameGameMode.h"
#include "SGamePlayerController.h"


ASGameGameMode::ASGameGameMode()
{
	
	// use our own player controller class
	PlayerControllerClass = ASGamePlayerController::StaticClass();
	UE_LOG(LogSGameProcedure, Log, TEXT("Game Mode construction complete!"));
}

void ASGameGameMode::BeginPlay()
{
	Super::BeginPlay();

	MessageEndPoint = FMessageEndpoint::Builder("Gameplay_GameMode").Handling<FMessage_Gameplay_GameStatusUpdate>(this, &ASGameGameMode::HandleGameStatusUpdate);

	check(MessageEndPoint.IsValid());

	MessageEndPoint->Subscribe<FMessage_Gameplay_GameStatusUpdate>();
}

void ASGameGameMode::HandleGameStatusUpdate(const FMessage_Gameplay_GameStatusUpdate& Message, const IMessageContextRef& Context)
{
	CurrentGameGameStatus = Message.NewGameStatus;

	switch (CurrentGameGameStatus)
	{
	case ESGGameStatus::EGS_Init:
		break;
	case ESGGameStatus::EGS_GameStart:
		break;
	case ESGGameStatus::EGS_RondBegin:
		OnBeginRound();
		break;
	case ESGGameStatus::EGS_PlayerTurnBegin:
		OnPlayerTurnBegin();
		break;
	case ESGGameStatus::EGS_PlayerRegenerate:
		OnPlayerRegenerate();
		break;
	case ESGGameStatus::EGS_PlayerSkillCD:
		OnPlayerSkillCD();
		break;
	case ESGGameStatus::EGS_PlayerBeginInput:
		OnPlayerBeginInputStage();
		break;
	case ESGGameStatus::EGS_PlayerEndBuildPath:
		OnPlayerEndBuildPathStage();
		break;
	case ESGGameStatus::EGS_PlayerEndInput:
		OnPlayerEndInputStage();
		break;
	case ESGGameStatus::EGS_EnemyAttack:
		OnEnemyAttackStage();
		break;
	case ESGGameStatus::EGS_RoundEnd:
		OnRoundEndStage();
		break;
	case ESGGameStatus::EGS_GameOver:
		OnGameOver();
		break;
	default:
		UE_LOG(LogSGameProcedure, Error, TEXT("Unhandled game status"));
		break;
	}
}

void ASGameGameMode::OnBeginRound()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Round begin"));

	check(MessageEndPoint.IsValid());

	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_PlayerTurnBegin;

	MessageEndPoint->Publish(Message, EMessageScope::Process);
}

void ASGameGameMode::OnPlayerTurnBegin()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Player turn begin"));

	check(MessageEndPoint.IsValid());

	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_PlayerRegenerate;

	MessageEndPoint->Publish(Message, EMessageScope::Process);
}

void ASGameGameMode::OnPlayerRegenerate()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Player regenerate"));

	check(MessageEndPoint.IsValid());

	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_PlayerSkillCD;

	MessageEndPoint->Publish(Message, EMessageScope::Process);
}

void ASGameGameMode::OnPlayerSkillCD()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Player skill cd"));

	check(MessageEndPoint.IsValid());

	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_PlayerBeginInput;

	MessageEndPoint->Publish(Message, EMessageScope::Process);
}

void ASGameGameMode::OnPlayerBeginInputStage()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Player begin input"));

	check(MessageEndPoint.IsValid());

	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_PlayerEndBuildPath;

	MessageEndPoint->Publish(Message, EMessageScope::Process);
}

void ASGameGameMode::OnPlayerEndBuildPathStage()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Player build path"));

	check(MessageEndPoint.IsValid());

	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_PlayerEndInput;

	MessageEndPoint->Publish(Message, EMessageScope::Process);
}

void ASGameGameMode::OnPlayerEndInputStage()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Player end input"));

	check(MessageEndPoint.IsValid());

	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_EnemyAttack;

	MessageEndPoint->Publish(Message, EMessageScope::Process);
}

void ASGameGameMode::OnEnemyAttackStage()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Enemy attack"));

	check(MessageEndPoint.IsValid());

	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_RoundEnd;

	MessageEndPoint->Publish(Message, EMessageScope::Process);

}

void ASGameGameMode::OnRoundEndStage()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Round end"));

	
}

void ASGameGameMode::OnGameOver()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Game over"));

	
}
