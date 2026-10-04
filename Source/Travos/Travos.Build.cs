// Copyright Epic Games, Inc. All Rights Reserved.

using System.Linq;
using UnrealBuildTool;

public class Travos : ModuleRules
{
	public Travos(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_7;
		
		// [CD/CI] For Code Coverage to run properly you can toggle optimization based on a custom flag: WITH_COVERAGE=1
		// To Activate, run build with: -define:WITH_COVERAGE=1
		if (Target.GlobalDefinitions.Contains("WITH_COVERAGE=1"))
		{
			OptimizeCode = CodeOptimization.Never;
			bUseUnity = false;
		}
		
		CppCompileWarningSettings.NonInlinedGenCppWarningLevel = WarningLevel.Warning;		
		
		PublicDependencyModuleNames.AddRange([
				"Core",
				"Engine",
				"CoreUObject",
				"WorldPartitionEditor",
				"Landscape", 
				"DeveloperSettings"
				// ... add other public dependencies that you statically link with here ...
			]
			);
		
		PrivateDependencyModuleNames.AddRange([
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			]
			);
		
		if (Target.Type == TargetRules.TargetType.Editor)
		{
			PrivateDependencyModuleNames.AddRange([
				"MessageLog"
			]);
		}
	}
}
