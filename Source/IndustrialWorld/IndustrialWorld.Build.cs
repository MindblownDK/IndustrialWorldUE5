// Copyright MindblownDK. IndustrialWorld — UE 5.7.4 rebuild.
using UnrealBuildTool;

public class IndustrialWorld : ModuleRules
{
	public IndustrialWorld(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		CppStandard = CppStandardVersion.Cpp20;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"GeometryCore",
			"GeometryFramework",
			"ProceduralMeshComponent",
			"RealtimeMeshComponent",
			"UMG",
			"Slate",
			"SlateCore",
			"RenderCore",
			"RHI"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Projects",
			"DeveloperSettings"
		});

		// Voxel meshing is hot-path; keep optimizations on even in Development.
		MinFilesUsingPrecompiledHeaderOverride = 1;
		bUseUnity = true;
	}
}
