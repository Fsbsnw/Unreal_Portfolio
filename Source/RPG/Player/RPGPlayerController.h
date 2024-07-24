// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "RPGPlayerController.generated.h"

class UInputAction;
class UInputMappingContext;
class IRPGEnemyInterface;

/**
 * 
 */
UCLASS()
class RPG_API ARPGPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
public:
	virtual void SetupInputComponent() override;
	virtual void PlayerTick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Inputs")
	UInputMappingContext* DefaultContext;

	void RotateToCursor();

	void CursorTrace();

	TScriptInterface<IRPGEnemyInterface> LastActor;
	TScriptInterface<IRPGEnemyInterface> ThisActor;
};
