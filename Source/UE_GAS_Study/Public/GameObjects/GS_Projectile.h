// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GS_Projectile.generated.h"

class UGameplayEffect;
class UProjectileMovementComponent;

UCLASS()
class UE_GAS_STUDY_API AGS_Projectile : public AActor
{
	GENERATED_BODY()

public:
	AGS_Projectile();
	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|Damage", meta = (ExposeOnSpawn, ClampMin = "0.0"))
	float Damage{-25.f};
	
	UFUNCTION(BlueprintImplementableEvent, Category = "GAS|Projectile")
	void SpawnImpactEffect();
	
private:
	UPROPERTY(VisibleAnywhere, Category = "GAS|Projectile")
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;
	
	UPROPERTY(EditDefaultsOnly, Category = "GAS|Damage")
	TSubclassOf<UGameplayEffect> DamageEffect;

};
