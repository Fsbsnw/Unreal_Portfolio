// Copyright Epic Games, Inc. All Rights Reserved.


#include "RPGGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Spawn/EnemySpawnPoint.h"
#include "Character/PlayerCharacter/RPGPlayerCharacter.h"
#include "Character/Guardian/RPGEnemyGuardian.h"
#include "Enemy/RPGEnemyAIController.h"

void ARPGGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemySpawnPoint::StaticClass(), SpawnPoints);

    SpawnEnemy();
}

void ARPGGameModeBase::SpawnEnemy()
{
    int32 idx = FMath::RandRange(0, SpawnPoints.Num() - 1);
    
    float CurrentTime = UGameplayStatics::GetTimeSeconds(GetWorld());
    if ((CurrentTime / 5) > Stage)
    {
        Stage++;       
        MinCoolTime = FMath::Clamp(MinCoolTime - 0.5f , 0.5f, 10.f);
        MaxCoolTime = FMath::Clamp(MaxCoolTime - 1.0f , 1.0f, 10.f);
    }

    // Spawn and set lifespan
    ARPGEnemyGuardian* Guardian = GetWorld()->SpawnActor<ARPGEnemyGuardian>(GuardianClass, SpawnPoints[idx]->GetActorLocation(), SpawnPoints[idx]->GetActorRotation());
    if (Guardian) 
    {        
        Guardian->SetLifeSpan(5.f);
    }

    float SpawnCoolTime = FMath::RandRange(MinCoolTime, MaxCoolTime);
    GetWorld()->GetTimerManager().SetTimer(SpawnEnemyHandle, this, &ARPGGameModeBase::SpawnEnemy, SpawnCoolTime);

    UE_LOG(LogTemp, Warning, TEXT("Current Time : %f, Stage : %d"), CurrentTime, Stage);
}
