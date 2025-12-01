#include "MyAssetTypeActions.h"
#include "MyAsset.h"
#include "MyAssetEditorToolkit.h"

FText FMyAssetTypeActions::GetName() const
{
    return FText::FromString(TEXT("Custom Asset"));
}

FColor FMyAssetTypeActions::GetTypeColor() const
{
	return FColor(50, 150, 255);
}

UClass* FMyAssetTypeActions::GetSupportedClass() const
{
	return UMyAsset::StaticClass();
}

void FMyAssetTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
    for (UObject* Obj : InObjects)
    {
        if (UMyAsset* Asset = Cast<UMyAsset>(Obj))
        {
            TSharedRef<FMyAssetEditorToolkit> Editor = MakeShared<FMyAssetEditorToolkit>();
            Editor->InitEditor(EToolkitMode::Standalone, EditWithinLevelEditor, Asset);
        }
    }
}

uint32 FMyAssetTypeActions::GetCategories()
{
    return EAssetTypeCategories::Misc;
}
