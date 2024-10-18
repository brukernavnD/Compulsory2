// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Compulsory2 : ModuleRules
{
	public Compulsory2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
        PublicDependencyModuleNames.AddRange(new string[] { "AIModule", "NavigationSystem", "GameplayTasks", "StateTreeModule", "GameplayStateTreeModule", "UMG", "GameplayTags", "Niagara"});
    }
}
