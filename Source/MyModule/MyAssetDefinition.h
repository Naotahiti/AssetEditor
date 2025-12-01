// Copyright © 2024 MajorT. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetDefinition.h"
#include "MyAssetDefinition.generated.h"

UCLASS()
class UMyAssetDefinition : public UAssetDefinition
{
	GENERATED_BODY()

protected:
	//~ Begin UAssetDefinitionDefault Interface
	virtual FText GetAssetDisplayName() const override;
	virtual FText GetAssetDescription(const FAssetData& AssetData) const override;
	virtual FLinearColor GetAssetColor() const override;
	virtual TSoftClassPtr<UObject> GetAssetClass() const override;
	virtual TConstArrayView<FAssetCategoryPath> GetAssetCategories() const override;
	//~ End UAssetDefinitionDefault Interface
};

