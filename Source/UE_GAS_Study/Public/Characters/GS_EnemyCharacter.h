// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GS_BaseCharacter.h"
#include "GS_EnemyCharacter.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

UCLASS()
class UE_GAS_STUDY_API AGS_EnemyCharacter : public AGS_BaseCharacter
{
	GENERATED_BODY()

public:
	AGS_EnemyCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual UAttributeSet* GetAttributeSet() const override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GAS|AI")
	float AcceptanceRadius{500.f};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GAS|AI")
	float MinAttackDelay{.1f};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GAS|AI")
	float MaxAttackDelay{.5f};
	
	UFUNCTION(BlueprintImplementableEvent)
	float GetTimelineLength();

protected:
	virtual void BeginPlay() override;
	
	virtual void HandleDeath() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
