// Copyright MindblownDK. IndustrialWorld — UE 5.7.4 rebuild.
using UnrealBuildTool;
using System.Collections.Generic;

public class IndustrialWorldTarget : TargetRules
{
	public IndustrialWorldTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("IndustrialWorld");
	}
}
