// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/GS_AttributeSet.h"

#include "GS_BaseCharacter.generated.h"

namespace GASTags
{
	extern UE_GAS_STUDY_API const FName Player;
}

class UAttributeSet;
class UGameplayEffect;
class UGameplayAbility;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FASCInitialized, UAbilitySystemComponent*, ASC, UAttributeSet*, AS);

UCLASS(Abstract)
class UE_GAS_STUDY_API AGS_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGS_BaseCharacter();

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual UAttributeSet* GetAttributeSet() const { return nullptr; }

	bool IsAlive() const { return bAlive; }
	void SetAlive(bool bAliveStatus) { bAlive = bAliveStatus; }

	UPROPERTY(BlueprintAssignable)
	FASCInitialized OnASCInitialized;

	UFUNCTION(BlueprintCallable, Category = "GAS|Death")
	virtual void HandleRespawn();

	UFUNCTION(BlueprintCallable, Category = "GAS|Attributes")
	void ResetAttributes();
	
	UFUNCTION(BlueprintImplementableEvent)
	void RotateToTarget(AActor* RotateTarget);

protected:
	void GiveStartupAbilities();
	void InitializeAttributes() const;

	void OnHealthChanged(const FOnAttributeChangeData& AttributeChangeData);
	virtual void HandleDeath();

private:
	UPROPERTY(EditDefaultsOnly, Category = "GAS|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "GAS|Effects")
	TSubclassOf<UGameplayEffect> InitializeAttributesEffect;
	
	UPROPERTY(EditDefaultsOnly, Category = "GAS|Effects")
	TSubclassOf<UGameplayEffect> ResetAttributesEffect;

	UPROPERTY(Replicated, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool bAlive = true;
};
