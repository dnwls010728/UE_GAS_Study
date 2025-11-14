// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AbilityTask/GS_WaitGameplayEvent.h"

UGS_WaitGameplayEvent* UGS_WaitGameplayEvent::WaitGameplayEventToActorProxy(AActor* TargetActor, FGameplayTag EventTag, bool OnlyTriggerOnce, bool OnlyMatchExact)
{
	UGS_WaitGameplayEvent* MyObj = NewObject<UGS_WaitGameplayEvent>();
	MyObj->SetAbilityActor(TargetActor);
	MyObj->Tag = EventTag;
	MyObj->OnlyTriggerOnce = OnlyTriggerOnce;
	MyObj->OnlyMatchExact = OnlyMatchExact;
	return MyObj;
}

void UGS_WaitGameplayEvent::StartActivation()
{
	Activate();
}
