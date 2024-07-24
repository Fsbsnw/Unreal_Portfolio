// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ARPGPlayerCharacter::ARPGPlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
    Camera->SetupAttachment(SpringArm);
}

void ARPGPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ARPGPlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}