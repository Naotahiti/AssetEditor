#include "MyModule.h"
#include "MyAssetTypeActions.h" 
#include "AssetToolsModule.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_MODULE(FMyModule, MyModule);

void FMyModule::StartupModule()
{
    UE_LOG(LogTemp, Warning, TEXT("MyModule started !"));
    IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

    MyCustomAssetCategory = AssetTools.RegisterAdvancedAssetCategory(
        FName(TEXT("MyCustomCategory")),           
        FText::FromString(TEXT("Ma Catégorie"))    
    );

    TSharedRef<IAssetTypeActions> Actions = MakeShared<FMyAssetTypeActions>(MyCustomAssetCategory);
    AssetTools.RegisterAssetTypeActions(Actions);
    RegisteredAssetTypeActions.Add(Actions);
}

void FMyModule::ShutdownModule()
{
    UE_LOG(LogTemp, Warning, TEXT("MyModule shutdown !"));
    if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
    {
        IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
        for (auto& Action : RegisteredAssetTypeActions)
        {
            AssetTools.UnregisterAssetTypeActions(Action.ToSharedRef());
        }
    }
    RegisteredAssetTypeActions.Empty();
}
