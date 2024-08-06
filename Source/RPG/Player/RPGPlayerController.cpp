// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "GameFramework/Character.h"
#include "../Character/PlayerCharacter/RPGPlayerCharacter.h"
#include "RPG/Enemy/RPGEnemyInterface.h"

void ARPGPlayerController::BeginPlay()
{
    Super::BeginPlay();

    PrimaryActorTick.bCanEverTick = true;    
    this->bShowMouseCursor = true;

	Possess(Cast<APawn>(GetOwner()));

    // IMC 초기화, 서버에서 이걸 실행하면 GetLocalPlayer에 대한 리턴이 없을 수 있음
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
		Subsystem->AddMappingContext(DefaultContext, 0);
    }
}

void ARPGPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
    {

    }
}

void ARPGPlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);

    CursorTrace();
}

void ARPGPlayerController::RotateToCursor()
{
    FHitResult HitResult;

    if (bool bHit = this->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult))
    {
        FVector ToTarget = HitResult.ImpactPoint - GetCharacter()->GetActorLocation();
        FRotator ToTargetRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);

        this->SetControlRotation(ToTargetRotation);
    }
}

void ARPGPlayerController::CursorTrace()
{
    FHitResult HitResult;
    bool bHit = GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
    if (!bHit) return;

    // Actors class : TScriptInterface
    LastActor = ThisActor;
    ThisActor = HitResult.GetActor();

    if (LastActor == nullptr)
    {
        if (ThisActor != nullptr)
        {
            ThisActor->HighlightActor();
        }
    }
    // LastActor is valid
    else
    {
        if (ThisActor != nullptr)
        {
            if (ThisActor != LastActor)
            {
                LastActor->UnHighlightActor();
                ThisActor->HighlightActor();
            }
        }
        // ThisActor is invalid
        else
        {
            LastActor->UnHighlightActor();
        }
    }
}
