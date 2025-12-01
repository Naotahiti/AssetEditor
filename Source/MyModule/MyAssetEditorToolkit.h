#pragma once


#include "CoreMinimal.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "MyGraph.h"
//#include "MyAssetEditorToolkit.generated.h"


class UMyAsset;
class SMyWidget;

class MYMODULE_API FMyAssetEditorToolkit : public FAssetEditorToolkit

{
public:
    void InitEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UMyAsset* InAsset);

    // FAssetEditorToolkit interface
    virtual FName GetToolkitFName() const override;
    virtual FText GetBaseToolkitName() const override;
    virtual FString GetWorldCentricTabPrefix() const override;
    virtual FLinearColor GetWorldCentricTabColorScale() const override;
    virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& TabManager) override;
    virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& TabManager) override;

private:
    UMyAsset* EditingAsset;

    // Le widget principal
    TSharedPtr<SMyWidget> GraphEditorWidget;

    // IDs des tabs
    static const FName GraphEditorTabId;

    // Spawner pour le tab du graph
    TSharedRef<SDockTab> SpawnGraphEditorTab(const FSpawnTabArgs& Args);
}; 





