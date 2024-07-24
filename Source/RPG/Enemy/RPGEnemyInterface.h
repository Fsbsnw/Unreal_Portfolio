// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGEnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class URPGEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPG_API IRPGEnemyInterface
{
	GENERATED_BODY()

public:
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;
};
