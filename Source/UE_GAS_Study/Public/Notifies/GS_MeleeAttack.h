// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GS_MeleeAttack.generated.h"

/**
 * 
 */
UCLASS()
class UE_GAS_STUDY_API UGS_MeleeAttack : public UAnimNotifyState
{
	GENERATED_BODY()
	
public:
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime) override;
	
private:
	UPROPERTY(EditAnywhere, Category = "GAS|Debugs")
	bool bDrawDebugs = true;
	
	UPROPERTY(EditAnywhere, Category = "GAS|Socket")
	FName SocketName{"FX_Trail_01_R"};
	
	UPROPERTY(EditAnywhere, Category = "GAS|Socket")
	float SocketExtensionOffset{40.f};
	
	UPROPERTY(EditAnywhere, Category = "GAS|Socket")
	float SphereTraceRadius{60.f};
	
	TArray<FHitResult> PerformSphereTrace(USkeletalMeshComponent* MeshComp) const;
	void SendEventsToActors(USkeletalMeshComponent* MeshComp, const TArray<FHitResult>& Hits) const;
};
