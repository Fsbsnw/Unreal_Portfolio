// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../Enemy/RPGEnemyInterface.h"
#include "../RPGCharacterBase.h"
#include "RPGEnemyGuardian.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API ARPGEnemyGuardian : public ARPGCharacterBase, public IRPGEnemyInterface
{
	GENERATED_BODY()

public:
	ARPGEnemyGuardian();
	
protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Controller")
	TSubclassOf<class ARPGEnemyAIController> EnemyAIControllerClass;

	class ARPGEnemyAIController* AIController;

	UFUNCTION()
	void Attack();
};
