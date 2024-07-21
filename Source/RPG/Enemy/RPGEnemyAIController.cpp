// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGEnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

void ARPGEnemyAIController::BeginPlay()
{
    Super::BeginPlay();

    Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
}

void ARPGEnemyAIController::OnPossess(APawn *InPawn)
{
    Super::OnPossess(InPawn);

    MoveToActor(Player, AttackRadius);
}

void ARPGEnemyAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
