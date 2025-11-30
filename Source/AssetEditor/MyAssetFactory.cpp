#include "MyAssetFactory.h"
#include "MyAsset.h"

UMyAssetFactory::UMyAssetFactory()
{
    // Specify the asset class this factory is supposed to create
    SupportedClass = UMyAsset::StaticClass();

    // Make sure to set this to true, otherwise it wont create the asset
    bCreateNew = true;

    // Set this to true, if you want to immediately start editing the asset after creation
    bEditAfterNew = true;
}
UObject* UMyAssetFactory::FactoryCreateNew(
    UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
    check(InClass->IsChildOf(UMyAsset::StaticClass()));
    return NewObject<UMyAsset>(InParent, InClass, InName, Flags);
}