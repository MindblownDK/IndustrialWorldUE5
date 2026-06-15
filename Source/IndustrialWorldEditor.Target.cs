// Copyright MindblownDK. IndustrialWorld — UE 5.7.4 rebuild.
using UnrealBuildTool;
using System.Collections.Generic;

public class IndustrialWorldEditorTarget : TargetRules
{
	public IndustrialWorldEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("IndustrialWorld");
	}
}
