// Fill out your copyright notice in the Description page of Project Settings.


#include "UE_GAS_Study/Public/Characters/GS_BaseCharacter.h"


AGS_BaseCharacter::AGS_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	// 전용 서버에서 뼈 업데이트를 위해 렌더링 여부에 관계없이 뼈 변환을 체크하고 새로 고침합니다
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

