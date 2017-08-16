
using UnrealBuildTool;

public class PointCloudRendererEditor : ModuleRules
{
	public PointCloudRendererEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.Add("PointCloudRendererEditor/Public");
        PrivateIncludePaths.Add("PointCloudRendererEditor/Private");

        PublicDependencyModuleNames.AddRange(
                new string[]
                {
                    "Core",
                    "CoreUObject",
                    "Slate",
                    "SlateCore",
                    "Engine",
                    "UnrealEd",
                    "PropertyEditor",
                    "BlueprintGraph",
                    "PointCloudRenderer"
                }
            );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                    "EditorStyle",
                    "AssetRegistry"
            }
        );

        // DynamicallyLoadedModuleNames.AddRange(new string[] { "PointCloudRenderer" });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
