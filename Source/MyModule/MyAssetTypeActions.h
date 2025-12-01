#pragma once


#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

class  FMyAssetTypeActions : public FAssetTypeActions_Base
{
public:
    // FAssetTypeActions_Base interface
    virtual FText GetName() const override;
    virtual FColor GetTypeColor() const override;
    virtual UClass* GetSupportedClass() const override;
    virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor) override;
    virtual uint32 GetCategories() override;


};

