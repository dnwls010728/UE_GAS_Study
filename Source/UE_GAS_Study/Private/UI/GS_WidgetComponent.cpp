// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GS_WidgetComponent.h"

#include "AbilitySystem/GS_AbilitySystemComponent.h"
#include "AbilitySystem/GS_AttributeSet.h"
#include "Blueprint/WidgetTree.h"
#include "Characters/GS_BaseCharacter.h"
#include "UI/GS_AttributeWidget.h"


void UGS_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	InitAbilitySystemData();

	if (!IsASCInitialized())
	{
		GASCharacter->OnASCInitialized.AddDynamic(this, &ThisClass::OnASCInitialized);
		return;
	}

	InitializedAttributeDelegate();
	
}

void UGS_WidgetComponent::InitAbilitySystemData()
{
	GASCharacter = Cast<AGS_BaseCharacter>(GetOwner());
	AttributeSet = Cast<UGS_AttributeSet>(GASCharacter->GetAttributeSet());
	AbilitySystemComponent = Cast<UGS_AbilitySystemComponent>(GASCharacter->GetAbilitySystemComponent());
}

bool UGS_WidgetComponent::IsASCInitialized() const
{
	return AbilitySystemComponent.IsValid() && AttributeSet.IsValid();
}

void UGS_WidgetComponent::InitializedAttributeDelegate()
{
	if (!AttributeSet->bAttributesInitialized)
	{
		AttributeSet->OnAttributesInitialized.AddDynamic(this, &ThisClass::BindToAttributeChanges);
	}
	else
	{
		BindToAttributeChanges();
	}
}

void UGS_WidgetComponent::BindWidgetToAttributeChanges(UWidget* WidgetObject, const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const
{
	UGS_AttributeWidget* AttributeWidget = Cast<UGS_AttributeWidget>(WidgetObject);
	if (!IsValid(AttributeWidget)) return;
	if (!AttributeWidget->MatchesAttribytes(Pair)) return;
	AttributeWidget->AvatorActor = GASCharacter;

	AttributeWidget->OnAttribyteChange(Pair, AttributeSet.Get(), 0.f);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Key).AddLambda([this, AttributeWidget, &Pair](const FOnAttributeChangeData& AttributeChangeData)
	{
		AttributeWidget->OnAttribyteChange(Pair, AttributeSet.Get(), AttributeChangeData.OldValue);
	});
}

void UGS_WidgetComponent::OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent = Cast<UGS_AbilitySystemComponent>(ASC);
	AttributeSet = Cast<UGS_AttributeSet>(AS);

	if (!IsASCInitialized()) return;
	InitializedAttributeDelegate();
}

void UGS_WidgetComponent::BindToAttributeChanges()
{
	for (const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair : AttributeMap)
	{
		BindWidgetToAttributeChanges(GetUserWidgetObject(), Pair);

		GetUserWidgetObject()->WidgetTree->ForEachWidget([this, &Pair](UWidget* ChildWidget)
		{
			BindWidgetToAttributeChanges(ChildWidget, Pair);
		});
	}
}

