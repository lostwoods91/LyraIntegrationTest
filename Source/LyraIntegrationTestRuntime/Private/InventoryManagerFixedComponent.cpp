// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManagerFixedComponent.h"

void UInventoryManagerFixedComponent::OnComponentCreated()
{
	Super::OnComponentCreated();

	// We need to register equipment and hotbar inventory components to work properly;
	// original UInventoryManagerComponent::OnComponentCreated() does not do this, but unluckily this works
	// when adding this component directly to the character because registration is done when compiling the blueprint.
	// If you add it at runtime instead (i.e. loading it as a game feature component), registration is skipped.
	GetEquipementInventory()->RegisterComponent();
	GetHotbarInventory()->RegisterComponent();
}
