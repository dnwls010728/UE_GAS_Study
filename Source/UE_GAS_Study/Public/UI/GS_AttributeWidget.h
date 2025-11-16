// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystem/GS_AttributeSet.h"
#include "Blueprint/UserWidget.h"
#include "GS_AttributeWidget.generated.h"

/**
 * 
 */
UCLASS()
class UE_GAS_STUDY_API UGS_AttributeWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|Attributes")
	FGameplayAttribute Attribute;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|Attributes")
	FGameplayAttribute MaxAttribute;

	void OnAttribyteChange(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair, UGS_AttributeSet* AttributeSet, float OldValue);
	bool MatchesAttribytes(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Attribute Change"))
	void BP_OnAttributeChange(float NewValue, float NewMaxValue, float OldValue);
	
	UPROPERTY(BlueprintReadOnly, Category = "GAS|Attributes")
	TWeakObjectPtr<AActor> AvatorActor;
};
