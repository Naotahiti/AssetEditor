#include "MyWidget.h"
#include "MyAsset.h"
#include "MyGraph.h"
#include "GraphEditorActions.h"
#include "Framework/Commands/GenericCommands.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Text/STextBlock.h"

void SMyWidget::Construct(const FArguments& InArgs, UMyAsset* InAsset)
{
    Asset = InAsset;

    // Créer le graph s'il n'existe pas
    if (!Asset->EdGraph)
    {
        Asset->EdGraph = NewObject<UMyGraph>(Asset, NAME_None, RF_Transactional);
    }

    // Créer le layout
    ChildSlot
        [
            SNew(SBorder)
                .BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
                [
                    SNew(SVerticalBox)

                        // Header
                        + SVerticalBox::Slot()
                        .AutoHeight()
                        .Padding(2.0f)
                        [
                            SNew(STextBlock)
                                .Text(FText::FromString(TEXT("Custom Asset Graph Editor")))
                                .Font(FAppStyle::GetFontStyle("HeadingLarge"))
                        ]

                        // Graph Editor
                        + SVerticalBox::Slot()
                        .FillHeight(1.0f)
                        [
                            CreateGraphEditorWidget()
                        ]
                ]
        ];
}

TSharedRef<SGraphEditor> SMyWidget::CreateGraphEditorWidget()
{
    FGraphAppearanceInfo AppearanceInfo;
    AppearanceInfo.CornerText = FText::FromString(TEXT("Custom Graph"));

    SGraphEditor::FGraphEditorEvents Events;
    Events.OnSelectionChanged = SGraphEditor::FOnSelectionChanged::CreateSP(this, &SMyWidget::OnSelectedNodesChanged);
    Events.OnSpawnNodeByShortcut = SGraphEditor::FOnSpawnNodeByShortcut::CreateSP(this, &SMyWidget::OnSpawnGraphNodeByShortcut);

    GraphEditor = SNew(SGraphEditor)
        .AdditionalCommands(MakeShareable(new FUICommandList()))
        .Appearance(AppearanceInfo)
        .GraphToEdit(Asset->EdGraph)
        .GraphEvents(Events)
        .ShowGraphStateOverlay(false);

    return GraphEditor.ToSharedRef();
}

void SMyWidget::OnSelectedNodesChanged(const TSet<UObject*>& NewSelection)
{
    // Gérer la sélection de nodes
}

FReply SMyWidget::OnSpawnGraphNodeByShortcut(FInputChord InChord, const FVector2D& InPosition)
{
    return FReply::Unhandled();
}