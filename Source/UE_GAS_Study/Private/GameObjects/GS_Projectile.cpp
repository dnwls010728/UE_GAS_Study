// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObjects/GS_Projectile.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Characters/GS_PlayerCharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameplayTags/GSTags.h"
#include "Utils/GS_BlueprintLibrary.h"


AGS_Projectile::AGS_Projectile()
{
	PrimaryActorTick.bCanEverTick = false;
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	
	bReplicates = true;
}

void AGS_Projectile::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	AGS_PlayerCharacter* PlayerCharacter = Cast<AGS_PlayerCharacter>(OtherActor);
	if (!IsValid(PlayerCharacter) || !PlayerCharacter->IsAlive()) return;
	
	UAbilitySystemComponent* AbilitySystemComponent = PlayerCharacter->GetAbilitySystemComponent();
	if (!IsValid(AbilitySystemComponent) || !HasAuthority()) return;
	
	FGameplayEventData Payload;
	Payload.Instigator = GetOwner();
	Payload.Target = PlayerCharacter;
	
	UGS_BlueprintLibrary::SendDamageEventToPlayer(PlayerCharacter, DamageEffect, Payload, GSTags::SetByCaller::Projectile, Damage, GSTags::None);
	
	SpawnImpactEffect();
	Destroy();
}

