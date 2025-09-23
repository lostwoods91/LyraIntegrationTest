// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryManagerComponent.h"
#include "InventoryManagerFixedComponent.generated.h"

/**
 * 
 */
UCLASS()
class LYRAINTEGRATIONTESTRUNTIME_API UInventoryManagerFixedComponent : public UInventoryManagerComponent
{
	GENERATED_BODY()

public:
	virtual void OnComponentCreated() override;
};
