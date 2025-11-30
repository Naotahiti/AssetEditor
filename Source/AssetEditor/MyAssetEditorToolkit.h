#pragma once


#include "Toolkits/AssetEditorToolkit.h"
#include "MyAssetEditorToolkit.generated.h"

class UMyAsset;


class ASSETEDITOR_API FMyAssetEditorToolkit : class FAssetEditorToolkit

{
public:


    void InitMyAssetEditor(
        const EToolkitMode::Type Mode,
        const TSharedPtr<class IToolkitHost>& InitToolkitHost,
        UMyAsset* InAsset);


    virtual FName GetToolkitFName() const override;
    virtual FText GetBaseToolkitName() const override;
    virtual FString GetWorldCentricTabPrefix() const override;
    virtual FLinearColor GetWorldCentricTabColorScale() const override;

protected:
    UMyAsset* EditedAsset;


};

