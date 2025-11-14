// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GS_EnemyCharacter.h"

#include "AbilitySystem/GS_AbilitySystemComponent.h"
#include "AbilitySystem/GS_AttributeSet.h"
#include "Runtime/AIModule/Classes/AIController.h"


AGS_EnemyCharacter::AGS_EnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UGS_AbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UGS_AttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* AGS_EnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AGS_EnemyCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

void AGS_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (!IsValid(GetAbilitySystemComponent())) return;

	GetAbilitySystemComponent()->InitAbilityActorInfo(this, this);
	OnASCInitialized.Broadcast(GetAbilitySystemComponent(), GetAttributeSet());
	
	if (!HasAuthority()) return;

	GiveStartupAbilities();
	InitializeAttributes();

	UGS_AttributeSet* GS_AttributeSet = Cast<UGS_AttributeSet>(GetAttributeSet());
	if (!IsValid(GS_AttributeSet)) return;
	
	GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(GS_AttributeSet->GetHealthAttribute()).AddUObject(this, &ThisClass::OnHealthChanged);
	
}

void AGS_EnemyCharacter::HandleDeath()
{
	Super::HandleDeath();
	
	AAIController* AIController = GetController<AAIController>();
	if (!IsValid(AIController)) return;
	
	AIController->StopMovement();
}

