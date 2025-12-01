#include "MyAssetEditorToolkit.h"


#include "MyAsset.h"
#include "Widgets/Docking/SDockTab.h"
#include "Editor/WorkspaceMenuStructure/Public/WorkspaceMenuStructureModule.h"
#include "PropertyEditorModule.h"
#include "MyWidget.h"

const FName FMyAssetEditorToolkit::GraphEditorTabId(TEXT("MyCustomAssetEditor_Graph"));

void FMyAssetEditorToolkit::InitEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UMyAsset* InAsset)
{
    EditingAsset = InAsset;

    // Créer le widget de l'éditeur
    GraphEditorWidget = SNew(SMyWidget, EditingAsset);

    // Layout par défaut
    const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_MyCustomAssetEditor_Layout_v1")
        ->AddArea
        (
            FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
            ->Split
            (
                FTabManager::NewStack()
                ->SetSizeCoefficient(0.1f)
                ->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
                ->SetHideTabWell(true)
            )
            ->Split
            (
                FTabManager::NewStack()
                ->SetSizeCoefficient(0.9f)
                ->AddTab(GraphEditorTabId, ETabState::OpenedTab)
            )
        );

    // Initialiser l'asset editor
    InitAssetEditor(Mode, InitToolkitHost, FName(TEXT("MyCustomAssetEditorApp")), StandaloneDefaultLayout, true, true, InAsset);
}

FName FMyAssetEditorToolkit::GetToolkitFName() const
{
    return FName(TEXT("MyCustomAssetEditor"));
}

FText FMyAssetEditorToolkit::GetBaseToolkitName() const
{
    return FText::FromString(TEXT("Custom Asset Editor"));
}

FString FMyAssetEditorToolkit::GetWorldCentricTabPrefix() const
{
    return TEXT("MyCustomAsset");
}

FLinearColor FMyAssetEditorToolkit::GetWorldCentricTabColorScale() const
{
    return FLinearColor(0.3f, 0.5f, 0.9f);
}


void FMyAssetEditorToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
    WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(FText::FromString(TEXT("Custom Asset Editor")));

    FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

    InTabManager->RegisterTabSpawner(GraphEditorTabId, FOnSpawnTab::CreateSP(this, &FMyAssetEditorToolkit::SpawnGraphEditorTab))
        .SetDisplayName(FText::FromString(TEXT("Graph")))
        .SetGroup(WorkspaceMenuCategory.ToSharedRef());
}

void FMyAssetEditorToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
    FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
    InTabManager->UnregisterTabSpawner(GraphEditorTabId);
}

TSharedRef<SDockTab> FMyAssetEditorToolkit::SpawnGraphEditorTab(const FSpawnTabArgs& Args)
{
    return SNew(SDockTab)
        .Label(FText::FromString(TEXT("Graph")))
        [
            GraphEditorWidget.ToSharedRef()
        ];
}