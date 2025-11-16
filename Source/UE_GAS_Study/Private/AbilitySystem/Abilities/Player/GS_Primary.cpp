// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/Player/GS_Primary.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayTags/GSTags.h"

void UGS_Primary::SendHitReactEventToActors(const TArray<AActor*>& ActorsHit)
{
	for (AActor* HitActor : ActorsHit)
	{
		FGameplayEventData Payload;
		Payload.Instigator = GetAvatarActorFromActorInfo();
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(HitActor, GSTags::Events::Enemy::HitReact, Payload);
	}
}
