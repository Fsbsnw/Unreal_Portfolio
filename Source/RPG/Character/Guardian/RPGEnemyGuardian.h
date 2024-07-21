// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../RPGCharacterBase.h"
#include "RPGEnemyGuardian.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API ARPGEnemyGuardian : public ARPGCharacterBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Controller")
	TSubclassOf<class ARPGEnemyAIController> EnemyAIControllerClass;

	class ARPGEnemyAIController* AIController;
};
