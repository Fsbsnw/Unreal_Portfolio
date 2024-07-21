// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RPGGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API ARPGGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, Category = "Spawn")
	TArray<AActor*> SpawnPoints;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	TSubclassOf<class ARPGEnemyGuardian> GuardianClass;

	void SpawnEnemy();

	FTimerHandle SpawnEnemyHandle;
	float MinCoolTime = 5.0f;
	float MaxCoolTime = 10.0f;
	int32 Stage;
};
