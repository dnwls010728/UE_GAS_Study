// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GS_PlayerController.generated.h"

struct FGameplayTag;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class UE_GAS_STUDY_API AGS_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "GAS|Input")
	TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts;

	UPROPERTY(EditDefaultsOnly, Category = "GAS|Input|Movement")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = "GAS|Input|Movement")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "GAS|Input|Movement")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "GAS|Input|Abilities")
	TObjectPtr<UInputAction> PrimaryAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "GAS|Input|Abilities")
	TObjectPtr<UInputAction> SecondaryAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "GAS|Input|Abilities")
	TObjectPtr<UInputAction> TertiaryAction;

	void Jump();
	void StopJumping();
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Primary();
	void Secondary();
	void Tertiary();
	void ActivateAbility(const FGameplayTag& AbilityTag) const;
	
	bool IsAlive() const;
};
