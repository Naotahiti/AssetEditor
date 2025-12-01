using UnrealBuildTool;

public class MyModule : ModuleRules
{
    public MyModule(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new string[]
               {
            "Core",
            "CoreUObject",
            "Engine",
            "Slate",              
            "SlateCore",         
            "InputCore",          
            "UnrealEd",
            "AssetTools",
             "AssetDefinition",
            "GraphEditor",
            "EditorStyle",        
            "ToolMenus"
               });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "AppFramework"        
        });
    }

}