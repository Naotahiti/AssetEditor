#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "GraphEditor.h"

class UMyAsset;
class SGraphEditor;

DECLARE_DELEGATE(FTextChanged)

class MYMODULE_API SMyWidget : public SCompoundWidget
{
public:
    SLATE_BEGIN_ARGS(SMyWidget) {}
        SLATE_ATTRIBUTE(FColor, BackgroundColor)
        SLATE_ATTRIBUTE(FName, Text)
        SLATE_EVENT(FTextChanged, OnTextChanger)
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs, UMyAsset* InAsset);

private:
    
    UMyAsset* Asset;

    //  graph editor widget
    TSharedPtr<SGraphEditor> GraphEditor;

    
    TSharedRef<SGraphEditor> CreateGraphEditorWidget();

  
    void OnSelectedNodesChanged(const TSet<UObject*>& NewSelection);
    FReply OnSpawnGraphNodeByShortcut(FInputChord InChord, const FVector2D& InPosition);
};
