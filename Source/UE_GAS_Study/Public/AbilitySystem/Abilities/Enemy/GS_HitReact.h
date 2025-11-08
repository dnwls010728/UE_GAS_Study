// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/GS_GameplayAbility.h"
#include "GS_HitReact.generated.h"

/**
 * 
 */
UCLASS()
class UE_GAS_STUDY_API UGS_HitReact : public UGS_GameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "GAS|Abilities")
	void CacheHitDirectionVectors(AActor* Instigator);
	
	UPROPERTY(BlueprintReadOnly, Category = "GAS|Abilities")
	FVector AvatarForward;
	
	UPROPERTY(BlueprintReadOnly, Category = "GAS|Abilities")
	FVector ToInstigator;
};
