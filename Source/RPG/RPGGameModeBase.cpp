// Copyright Epic Games, Inc. All Rights Reserved.


#include "RPGGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Spawn/EnemySpawnPoint.h"
#include "Character/PlayerCharacter/RPGPlayerCharacter.h"
#include "Character/Guardian/RPGEnemyGuardian.h"

void ARPGGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemySpawnPoint::StaticClass(), SpawnPoints);

    SpawnEnemy();
}

void ARPGGameModeBase::SpawnEnemy()
{
    int32 idx = FMath::RandRange(0, SpawnPoints.Num() - 1);
    

    GetWorld()->SpawnActor<ARPGEnemyGuardian>(GuardianClass, SpawnPoints[idx]->GetActorLocation(), SpawnPoints[idx]->GetActorRotation());

    GetWorld()->GetTimerManager().SetTimer(SpawnEnemyHandle, this, &ARPGGameModeBase::SpawnEnemy, 2);
}
