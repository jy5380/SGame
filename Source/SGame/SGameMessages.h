#pragma once

#include "SGameMessages.generated.h"

UENUM()
enum class ESGGameStatus : uint8
{
	EGS_Init,
	EGS_GameStart,
	EGS_RondBegin,
	EGS_PlayerTurnBegin,
	EGS_PlayerRegenerate,
	EGS_PlayerSkillCD,
	EGS_PlayerBeginInput,
	EGS_PlayerEndBuildPath,
	EGS_PlayerEndInput,
	EGS_EnemyAttack,
	EGS_RoundEnd,
	EGS_GameOver,
};

USTRUCT()
struct FMessage_Gameplay_GameStatusUpdate
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY()
		ESGGameStatus NewGameStatus;
};