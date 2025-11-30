#pragma once
#include "MyWidget.generated.h"

DECLARE_DELEGATE(FTextChanged)

class ASSETEDITOR_API SMyWidget : public SCompoundWidget
{
public:
    SLATE_BEGIN_ARGS(SMyWidget) {}
        SLATE_ATTRIBUTE(FColor , BackgroundColor)
        SLATE_ATTRIBUTE(FName , Text)
        SLATE_EVENT(FTextChanged, OnTextChanger)
    SLATE_END_ARGS()


    void Construct(FArguments& InArgs);

    SNew(SGraphEditor)
};
