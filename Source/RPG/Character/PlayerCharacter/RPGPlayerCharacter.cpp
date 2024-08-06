// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGPlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "RPG/Player/RPGPlayerController.h"
#include "RPG/Player/RPGPlayerState.h"
#include "RPG/UI/HUD/RPGHUD.h"

ARPGPlayerCharacter::ARPGPlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
    Camera->SetupAttachment(SpringArm);
}

void ARPGPlayerCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    InitAbilityActorInfo();
}

void ARPGPlayerCharacter::OnRep_PlayerState()
{
    Super::OnRep_PlayerState();

    InitAbilityActorInfo();
}

void ARPGPlayerCharacter::InitAbilityActorInfo()
{
    ARPGPlayerState* RPGPlayerState = GetPlayerState<ARPGPlayerState>();
    check(RPGPlayerState);

    RPGPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(RPGPlayerState, this);
    AbilitySystemComponent = RPGPlayerState->GetAbilitySystemComponent();
    AttributeSet = RPGPlayerState->GetAttributeSet();

    if (ARPGPlayerController* RPGPlayerController = Cast<ARPGPlayerController>(GetController()))
    {
        if (ARPGHUD* ARPHUD = Cast<ARPGHUD>(RPGPlayerController->GetHUD()))
        {
            ARPHUD->InitOverlay(RPGPlayerController, RPGPlayerState, AbilitySystemComponent, AttributeSet);
        }
    }
}

void ARPGPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ARPGPlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}