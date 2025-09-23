// Fill out your copyright notice in the Description page of Project Settings.

#include "IntegrationTestFunctionLibrary.h"

#include "Inventory/InventoryFragment_EquippableItem.h"
#include "Inventory/LyraInventoryItemInstance.h"

TSubclassOf<ULyraInventoryItemDefinition> UIntegrationTestFunctionLibrary::GetItemDefinition(
	ULyraInventoryItemInstance* ItemInstance)
{
	return ItemInstance ? ItemInstance->GetItemDef() : nullptr;
}

TSubclassOf<ULyraEquipmentDefinition> UIntegrationTestFunctionLibrary::GetEquipmentDefinition(
	UInventoryFragment_EquippableItem* Fragment_EquippableItem)
{
	return Fragment_EquippableItem ? Fragment_EquippableItem->EquipmentDefinition : nullptr;
}
