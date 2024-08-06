// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGPlayerState.h"
#include "../AbilitySystem/RPGAttributeSet.h"
#include "../AbilitySystem/RPGAbilitySystemComponent.h"

ARPGPlayerState::ARPGPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<URPGAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<URPGAttributeSet>("AttributeSet");
	
	// Updates 100 times per second
	NetUpdateFrequency = 100.f;
}