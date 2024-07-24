// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGEnemyGuardian.h"
#include "../../Enemy/RPGEnemyAIController.h"
#include "RPG/AbilitySystem/RPGAbilitySystemComponent.h"
#include "RPG/AbilitySystem/RPGAttributeSet.h"

ARPGEnemyGuardian::ARPGEnemyGuardian()
{
    GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
    
    AbilitySystemComponent = CreateDefaultSubobject<URPGAbilitySystemComponent>("AbilitySystemComponent");
    AbilitySystemComponent->SetIsReplicated(true);

    AttributeSet = CreateDefaultSubobject<URPGAttributeSet>("AttributeSet"); 
}

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

void ARPGEnemyGuardian::Tick(float DeltaTime)
{

}

void ARPGEnemyGuardian::HighlightActor()
{
    GetMesh()->SetRenderCustomDepth(true);
}

void ARPGEnemyGuardian::UnHighlightActor()
{
    GetMesh()->SetRenderCustomDepth(false);
}

void ARPGEnemyGuardian::Attack()
{
    UE_LOG(LogTemp, Warning, TEXT("Enemy Is Attacking"));
}
