// Copyright MindblownDK. IndustrialWorld — UE 5.7.4 rebuild.
using UnrealBuildTool;
using System.Collections.Generic;

public class IndustrialWorldEditorTarget : TargetRules
{
	public IndustrialWorldEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		ExtraModuleNames.Add("IndustrialWorld");
	}
}
