// Copyright © 2024 MajorT. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MyAsset.generated.h"

class UEdGraph;

UCLASS(BlueprintType)
class UMyAsset : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UMyAsset();

public:

 
    /** My dummy float for testing. */
    UPROPERTY(EditDefaultsOnly, Category = "Test")
    float MyDummyFloat;

    /** My dummy string for testing. */
    UPROPERTY(EditDefaultsOnly, Category = "Test")
    FText MyDummyString;

    UPROPERTY()
    UEdGraph* EdGraph;


};
