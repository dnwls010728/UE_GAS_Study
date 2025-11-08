// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GS_BaseCharacter.h"
#include "GS_EnemyCharacter.generated.h"

class UAbilitySystemComponent;

UCLASS()
class UE_GAS_STUDY_API AGS_EnemyCharacter : public AGS_BaseCharacter
{
	GENERATED_BODY()

public:
	AGS_EnemyCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};
