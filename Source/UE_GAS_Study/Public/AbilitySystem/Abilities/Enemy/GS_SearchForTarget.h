// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/GS_GameplayAbility.h"
#include "GS_SearchForTarget.generated.h"

namespace EPathFollowingResult
{
	enum Type : int;
}

class UAITask_MoveTo;
class AGS_BaseCharacter;
class UAbilityTask_WaitDelay;
class UGS_WaitGameplayEvent;
class AAIController;
class AGS_EnemyCharacter;
/**
 * 
 */
UCLASS()
class UE_GAS_STUDY_API UGS_SearchForTarget : public UGS_GameplayAbility
{
	GENERATED_BODY()
	
public:
	UGS_SearchForTarget();
	
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	
	TWeakObjectPtr<AGS_EnemyCharacter> OwningEnemy;
	TWeakObjectPtr<AAIController> OwningAIController;
	TWeakObjectPtr<AGS_BaseCharacter> TargetBaseCharacter;
	
private:
	UPROPERTY()
	TObjectPtr<UGS_WaitGameplayEvent> WaitGameplayEventTask;
	
	UPROPERTY()
	TObjectPtr<UAbilityTask_WaitDelay> SearchDelayTask;
	
	UPROPERTY()
	TObjectPtr<UAITask_MoveTo> MoveToLocationOrActorTask;
	
	UPROPERTY()
	TObjectPtr<UAbilityTask_WaitDelay> AttackDelayTask;
	
	void StartSearch();
	
	UFUNCTION()
	void EndAttackEventReceived(FGameplayEventData Payload);
	
	UFUNCTION()
	void Search();
	
	void MoveToTargetAndAttack();
	
	UFUNCTION()
	void AttackTarget(TEnumAsByte<EPathFollowingResult::Type> Result, AAIController* AIController);
	
	UFUNCTION()
	void Attack();
};
