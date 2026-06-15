// Copyright MindblownDK. IndustrialWorld — UE 5.7.4 rebuild.
using UnrealBuildTool;

public class IndustrialWorld : ModuleRules
{
	public IndustrialWorld(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		CppStandard = CppStandardVersion.Cpp20;

		// Phase A only needs the engine essentials. Heavier dependencies
		// (RealtimeMeshComponent, GeometryCore, UMG/Slate, EnhancedInput, ...)
		// are added in the phase that first #includes their headers, so the
		// module always compiles cleanly regardless of plugin install state.
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Projects"
		});
	}
}
