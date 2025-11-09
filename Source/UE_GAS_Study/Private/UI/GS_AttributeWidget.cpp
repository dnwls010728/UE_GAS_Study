// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GS_AttributeWidget.h"

void UGS_AttributeWidget::OnAttribyteChange(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair, UGS_AttributeSet* AttributeSet)
{
	const float AttributeValue = Pair.Key.GetNumericValue(AttributeSet);
	const float MaxAttributeValue = Pair.Value.GetNumericValue(AttributeSet);

	BP_OnAttributeChange(AttributeValue, MaxAttributeValue);
}

bool UGS_AttributeWidget::MatchesAttribytes(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const
{
	return Attribute == Pair.Key && MaxAttribute == Pair.Value;
}
