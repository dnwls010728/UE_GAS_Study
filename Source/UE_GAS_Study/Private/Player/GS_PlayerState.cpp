// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/GS_PlayerState.h"
#include "AbilitySystemComponent.h"

AGS_PlayerState::AGS_PlayerState()
{
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* AGS_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
