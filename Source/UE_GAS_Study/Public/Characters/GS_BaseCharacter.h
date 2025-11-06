// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GS_BaseCharacter.generated.h"

UCLASS(Abstract)
class UE_GAS_STUDY_API AGS_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGS_BaseCharacter();
};
