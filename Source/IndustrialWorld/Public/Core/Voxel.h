// Copyright MindblownDK. IndustrialWorld — UE 5.7.4 rebuild.
//
// 3-byte voxel: Density + Material + WaterLevel.
//   Density:    signed byte (-128..127). > ISO_LEVEL = solid, else empty.
//   Material:   EVoxelMaterial (0..255).
//   WaterLevel: byte 0..255. 0 = dry, 255 = fully saturated.
// 3 bytes * 34^3 ≈ 118 KB per padded chunk — fits comfortably in L2 cache.
//
// Packed to 1-byte alignment so a chunk's voxel array can be memcpy'd to/from
// disk as a flat byte buffer (see Persistence module, later phase).
#pragma once

#include "CoreMinimal.h"
#include "Core/VoxelConstants.h"
#include "Materials/VoxelMaterial.h"
#include "Voxel.generated.h"

#pragma pack(push, 1)
USTRUCT(BlueprintType)
struct FVoxel
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voxel")
	int8 Density = -127;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voxel")
	uint8 Material = 0; // EVoxelMaterial as raw byte (kept byte for tight packing)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voxel")
	uint8 WaterLevel = 0;

	FVoxel() = default;

	FVoxel(int8 InDensity, uint8 InMaterial, uint8 InWaterLevel = 0)
		: Density(InDensity), Material(InMaterial), WaterLevel(InWaterLevel)
	{
	}

	FVoxel(int8 InDensity, EVoxelMaterial InMaterial, uint8 InWaterLevel = 0)
		: Density(InDensity), Material(static_cast<uint8>(InMaterial)), WaterLevel(InWaterLevel)
	{
	}

	FORCEINLINE bool IsSolid() const   { return Density > VoxelConstants::ISO_LEVEL; }
	FORCEINLINE bool HasWater() const  { return WaterLevel > 0; }

	/** Water fill fraction 0..1. */
	FORCEINLINE float WaterFill() const { return WaterLevel / 255.0f; }

	FORCEINLINE EVoxelMaterial GetMaterial() const { return static_cast<EVoxelMaterial>(Material); }
	FORCEINLINE void SetMaterial(EVoxelMaterial M) { Material = static_cast<uint8>(M); }

	FORCEINLINE bool operator==(const FVoxel& Other) const
	{
		return Density == Other.Density && Material == Other.Material && WaterLevel == Other.WaterLevel;
	}
	FORCEINLINE bool operator!=(const FVoxel& Other) const { return !(*this == Other); }

	static const FVoxel Empty;
	static const FVoxel Solid;
};
#pragma pack(pop)

// Guarantee the tight 3-byte layout the chunk serializer relies on.
static_assert(sizeof(FVoxel) == 3, "FVoxel must be exactly 3 bytes for chunk (de)serialization.");
