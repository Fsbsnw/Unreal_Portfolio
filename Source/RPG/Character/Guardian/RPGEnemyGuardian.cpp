// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGEnemyGuardian.h"
#include "../../Enemy/RPGEnemyAIController.h"

void ARPGEnemyGuardian::BeginPlay()
{
    Super::BeginPlay();

    AIController = GetWorld()->SpawnActor<ARPGEnemyAIController>(EnemyAIControllerClass);

    if (AIController)
    {
        AIController->Possess(this);
    }
}

void ARPGEnemyGuardian::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (EndPlayReason == EEndPlayReason::Destroyed || EndPlayReason == EEndPlayReason::RemovedFromWorld)
    {

    }
}