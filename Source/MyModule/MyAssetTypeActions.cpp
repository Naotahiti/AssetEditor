#include "MyAssetTypeActions.h"
#include "MyAsset.h"
#include "MyAssetDefinition.h"
#include "MyAssetEditorToolkit.h"

FMyAssetTypeActions::FMyAssetTypeActions(uint32 InAssetCategory)
    : MyAssetCategory(InAssetCategory)
{
}

FText FMyAssetTypeActions::GetName() const
{
    UMyAsset* asset = GetMutableDefault<UMyAsset>();
    
    return FText::FromString(asset->MyDummyString);
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
 
    return MyAssetCategory;
}
