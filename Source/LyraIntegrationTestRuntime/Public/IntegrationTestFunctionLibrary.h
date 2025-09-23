// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "IntegrationTestFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class LYRAINTEGRATIONTESTRUNTIME_API UIntegrationTestFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Integration Test")
	static TSubclassOf<ULyraInventoryItemDefinition> GetItemDefinition(ULyraInventoryItemInstance* ItemInstance);

	UFUNCTION(BlueprintPure, Category = "Integration Test")
	static TSubclassOf<ULyraEquipmentDefinition> GetEquipmentDefinition(UInventoryFragment_EquippableItem* Fragment_EquippableItem);
};
