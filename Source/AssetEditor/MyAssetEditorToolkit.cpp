#include "MyAssetEditorToolkit.h"


#include "MyAsset.h"
#include "Widgets/Docking/SDockTab.h"
#include "Editor/WorkspaceMenuStructure/Public/WorkspaceMenuStructureModule.h"
#include "PropertyEditorModule.h"


#define LOCTEXT_NAMESPACE "MyAssetEditor"



FMyAssetEditorToolkit::FMyAssetEditorToolkit()
{
}

FName FMyAssetEditorToolkit::GetToolkitFName() const
{
    return FName("MyAssetEditor");
}

FText FMyAssetEditorToolkit::GetBaseToolkitName() const
{
    return LOCTEXT("MyAssetEditorName", "My Asset Editor");
}

FString FMyAssetEditorToolkit::GetWorldCentricTabPrefix() const
{
    return "MyAsset";
}

FLinearColor FMyAssetEditorToolkit::GetWorldCentricTabColorScale() const
{
    return FLinearColor(1, 0, 0);
}

#undef LOCTEXT_NAMESPACE
