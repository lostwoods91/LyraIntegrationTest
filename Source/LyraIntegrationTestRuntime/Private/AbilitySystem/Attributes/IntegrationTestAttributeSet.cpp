// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystem/Attributes/IntegrationTestAttributeSet.h"

#include "Net/UnrealNetwork.h"

UIntegrationTestAttributeSet::UIntegrationTestAttributeSet()
	: Speed(1.0f)
{
}

void UIntegrationTestAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UIntegrationTestAttributeSet, Speed, OldValue);
}

void UIntegrationTestAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UIntegrationTestAttributeSet, Speed, COND_OwnerOnly, REPNOTIFY_Always);
}
