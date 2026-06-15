// Copyright MindblownDK. IndustrialWorld — UE 5.7.4 rebuild.
//
// Byte-sized material identifier. ORDER MATTERS — values are serialized inside
// voxels and inside save files. Add NEW materials at the END only.
// Mirrors the original Unity MaterialId enum 1:1 so old-world intent is preserved,
// while the on-disk *chunk* format is brand new (hence MAJOR version bump to 5.x).
#pragma once

#include "CoreMinimal.h"
#include "VoxelMaterial.generated.h"

UENUM(BlueprintType)
enum class EVoxelMaterial : uint8
{
	Air         = 0   UMETA(DisplayName = "Air"),
	Stone       = 1   UMETA(DisplayName = "Stone"),
	Sand        = 2   UMETA(DisplayName = "Sand"),
	Clay        = 3   UMETA(DisplayName = "Clay"),
	Ice         = 4   UMETA(DisplayName = "Ice"),
	WaterVoxel  = 5   UMETA(DisplayName = "Water (Solid Voxel)"),
	WaterLiquid = 6   UMETA(DisplayName = "Water (Liquid)"),
	Iron        = 7   UMETA(DisplayName = "Iron Ore"),
	Copper      = 8   UMETA(DisplayName = "Copper Ore"),
	Coal        = 9   UMETA(DisplayName = "Coal"),
	Nickel      = 10  UMETA(DisplayName = "Nickel Ore"),
	Silicon     = 11  UMETA(DisplayName = "Silicon"),
	Cobalt      = 12  UMETA(DisplayName = "Cobalt Ore"),
	Silver      = 13  UMETA(DisplayName = "Silver Ore"),
	Gold        = 14  UMETA(DisplayName = "Gold Ore"),
	Magnesium   = 15  UMETA(DisplayName = "Magnesium Ore"),
	Platinum    = 16  UMETA(DisplayName = "Platinum Ore"),
	Uranium     = 17  UMETA(DisplayName = "Uranium Ore"),
	CrudeOil    = 18  UMETA(DisplayName = "Crude Oil"),
	Wood        = 19  UMETA(DisplayName = "Wood"),
	Bedrock     = 20  UMETA(DisplayName = "Bedrock"),

	// === Add custom materials below this line (END only) ===

	MAX         = 255 UMETA(Hidden)
};

/** Total number of distinct material slots we reserve palette/colour entries for. */
namespace VoxelMaterialTraits
{
	/** True for fluid-class materials that the (future) fluid system owns, not Surface Nets. */
	FORCEINLINE bool IsFluid(EVoxelMaterial M)
	{
		return M == EVoxelMaterial::WaterLiquid || M == EVoxelMaterial::CrudeOil;
	}

	/** True if a voxel of this material should be treated as unbreakable. */
	FORCEINLINE bool IsUnbreakable(EVoxelMaterial M)
	{
		return M == EVoxelMaterial::Bedrock;
	}

	/** True if mining this material yields an ore resource drop. */
	FORCEINLINE bool IsOre(EVoxelMaterial M)
	{
		switch (M)
		{
		case EVoxelMaterial::Iron:
		case EVoxelMaterial::Copper:
		case EVoxelMaterial::Coal:
		case EVoxelMaterial::Nickel:
		case EVoxelMaterial::Silicon:
		case EVoxelMaterial::Cobalt:
		case EVoxelMaterial::Silver:
		case EVoxelMaterial::Gold:
		case EVoxelMaterial::Magnesium:
		case EVoxelMaterial::Platinum:
		case EVoxelMaterial::Uranium:
			return true;
		default:
			return false;
		}
	}
}
