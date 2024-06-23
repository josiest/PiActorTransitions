// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PiActorTransitions : ModuleRules
{
    public PiActorTransitions(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[] {
            "Core",
            "CoreUObject",
            "Engine",
            "DeveloperSettings",
            "Paper2D"
        });
    }
}
