#include "MyModule.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_MODULE(FDefaultModuleImpl, MyModule);

void FMyModule::StartupModule()
{
    UE_LOG(LogTemp, Warning, TEXT("MyModule started !"));
}

void FMyModule::ShutdownModule()
{
    UE_LOG(LogTemp, Warning, TEXT("MyModule shutdown !"));
}
