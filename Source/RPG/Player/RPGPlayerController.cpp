// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "GameFramework/Character.h"
#include "../Character/PlayerCharacter/RPGPlayerCharacter.h"

void ARPGPlayerController::BeginPlay()
{
    Super::BeginPlay();

    this->bShowMouseCursor = true;

	Possess(Cast<APawn>(GetOwner()));

    // IMC 초기화
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

void ARPGPlayerController::Tick(float DeltaTime)
{
    RotateToCursor();
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