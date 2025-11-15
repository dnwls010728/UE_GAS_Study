// Fill out your copyright notice in the Description page of Project Settings.


#include "UE_GAS_Study/Public/Characters/GS_BaseCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameplayAbilitySpec.h"
#include "Net/UnrealNetwork.h"

namespace GASTags
{
	const FName Player = FName("Player");
}

AGS_BaseCharacter::AGS_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	// 전용 서버에서 뼈 업데이트를 위해 렌더링 여부에 관계없이 뼈 변환을 체크하고 새로 고침합니다
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

void AGS_BaseCharacter::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, bAlive);
}

UAbilitySystemComponent* AGS_BaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}

void AGS_BaseCharacter::HandleRespawn()
{
	bAlive = true;
}

void AGS_BaseCharacter::ResetAttributes()
{
	checkf(IsValid(ResetAttributesEffect), TEXT("ResetAttributesEffect가 설정되지 않았습니다."));
	if (!IsValid(GetAbilitySystemComponent())) return;

	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(ResetAttributesEffect, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}

void AGS_BaseCharacter::GiveStartupAbilities()
{
	for (const auto& Ability : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability);
		GetAbilitySystemComponent()->GiveAbility(AbilitySpec);
	}
}

void AGS_BaseCharacter::InitializeAttributes() const
{
	checkf(IsValid(InitializeAttributesEffect), TEXT("InitializeAttributesEffect가 설정되지 않았습니다."));

	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(InitializeAttributesEffect, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}

void AGS_BaseCharacter::OnHealthChanged(const FOnAttributeChangeData& AttributeChangeData)
{
	if (AttributeChangeData.NewValue <= 0.f)
	{
		HandleDeath();
	}
}

void AGS_BaseCharacter::HandleDeath()
{
	bAlive = false;
}

