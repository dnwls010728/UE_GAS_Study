// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Components/WidgetComponent.h"
#include "GS_WidgetComponent.generated.h"


class UAbilitySystemComponent;
class UGS_AttributeSet;
class UGS_AbilitySystemComponent;
class AGS_BaseCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UE_GAS_STUDY_API UGS_WidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TMap<FGameplayAttribute, FGameplayAttribute> AttributeMap;

private:
	TWeakObjectPtr<AGS_BaseCharacter> GASCharacter;
	TWeakObjectPtr<UGS_AbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<UGS_AttributeSet> AttributeSet;

	void InitAbilitySystemData();
	bool IsASCInitialized() const;
	void InitializedAttributeDelegate();
	void BindWidgetToAttributeChanges(UWidget* WidgetObject, const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const;

	UFUNCTION()
	void OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS);

	UFUNCTION()
	void BindToAttributeChanges();
};
