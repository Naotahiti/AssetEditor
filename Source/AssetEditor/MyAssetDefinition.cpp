#include "MyAssetDefinition.h"
#include "MyAsset.h"

FText UMyAssetDefinition::GetAssetDisplayName() const
{
	return FText::FromString(TEXT("My Asset"));
}


FText  UMyAssetDefinition::GetAssetDescription(const FAssetData& AssetData) const
	
{
	if (const UMyAsset* MyAsset = Cast<UMyAsset>(AssetData.GetAsset()))
	{
		return MyAsset->MyDummyString;
	}

	return FText::GetEmpty();
}


FLinearColor UMyAssetDefinition::GetAssetColor() const

{
	return FLinearColor(FColor::FromHex("#26601EFF"));
}

TSoftClassPtr<UObject> UMyAssetDefinition::GetAssetClass() const

{
	return UMyAsset::StaticClass();
}

TConstArrayView<FAssetCategoryPath> UMyAssetDefinition::GetAssetCategories() const

{
	static const auto Categories = {
FAssetCategoryPath(FText::FromName("My Category")),
	};

	return Categories;
}

