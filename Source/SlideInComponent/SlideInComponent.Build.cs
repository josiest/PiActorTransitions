// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SlideInComponent : ModuleRules
{
    public SlideInComponent(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[] {
            "Core",
            "CoreUObject",
            "Engine",
            "DeveloperSettings"
        });
    }
}
