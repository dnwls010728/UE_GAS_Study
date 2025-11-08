// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/GS_GameplayAbility.h"
#include "GS_Primary.generated.h"

/**
 * 
 */
UCLASS()
class UE_GAS_STUDY_API UGS_Primary : public UGS_GameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "GAS|Abilities")
	TArray<AActor*> HitBoxOverlapTest();
	
	UFUNCTION(BlueprintCallable, Category = "GAS|Abilities")
	void SendHitReactEventToActors(const TArray<AActor*>& ActorsHit);

private:
	void DrawHitBoxOverlapDebugs(const TArray<FOverlapResult>& OverlapResults, const FVector& HitBoxLocation) const;
	
	UPROPERTY(EditDefaultsOnly, Category = "GAS|Abilities")
	float HitBoxRadius = 100.f;

	UPROPERTY(EditDefaultsOnly, Category = "GAS|Abilities")
	float HitBoxForwardOffset = 200.f;

	UPROPERTY(EditDefaultsOnly, Category = "GAS|Abilities")
	float HitBoxElevationOffset = 20.f;
};
