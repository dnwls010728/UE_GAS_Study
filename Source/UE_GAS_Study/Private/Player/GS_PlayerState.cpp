// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/GS_PlayerState.h"
#include "AbilitySystem/GS_AbilitySystemComponent.h"
#include "AbilitySystem/GS_AttributeSet.h"

AGS_PlayerState::AGS_PlayerState()
{
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent = CreateDefaultSubobject<UGS_AbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UGS_AttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* AGS_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
