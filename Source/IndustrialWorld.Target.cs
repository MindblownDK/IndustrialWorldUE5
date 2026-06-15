// Copyright MindblownDK. IndustrialWorld — UE 5.7.4 rebuild.
using UnrealBuildTool;
using System.Collections.Generic;

public class IndustrialWorldTarget : TargetRules
{
	public IndustrialWorldTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		ExtraModuleNames.Add("IndustrialWorld");
	}
}
