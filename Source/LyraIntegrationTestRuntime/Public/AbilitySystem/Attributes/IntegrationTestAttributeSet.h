// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"

#include "AbilitySystem/Attributes/LyraAttributeSet.h"
#include "IntegrationTestAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class LYRAINTEGRATIONTESTRUNTIME_API UIntegrationTestAttributeSet : public ULyraAttributeSet
{
	GENERATED_BODY()

public:
	UIntegrationTestAttributeSet();
	
	ATTRIBUTE_ACCESSORS(UIntegrationTestAttributeSet, Speed);

protected:
	UFUNCTION()
	void OnRep_Speed(const FGameplayAttributeData& OldValue);
	
private:
	UPROPERTY(ReplicatedUsing = OnRep_Speed)
	FGameplayAttributeData Speed;
};
