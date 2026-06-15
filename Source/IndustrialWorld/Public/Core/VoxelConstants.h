// Copyright MindblownDK. IndustrialWorld — UE 5.7.4 rebuild.
//
// Global compile-time constants for the voxel engine.
// Tweak CHUNK_SIZE carefully — it affects memory & meshing cost cubically.
//
// NOTE ON UNITS: Unreal works in centimetres. One voxel = VOXEL_SIZE_UU world
// units. We keep 1 voxel = 100 uu (1 metre) so the world matches the original
// Unity scale where 1 voxel = 1 m.
#pragma once

#include "CoreMinimal.h"

namespace VoxelConstants
{
	// Chunk dimensions (cubic). 32 balances draw-call count vs meshing cost.
	inline constexpr int32 CHUNK_SIZE       = 32;
	// Padded with a 1-voxel border for seamless neighbour sampling during meshing.
	inline constexpr int32 CHUNK_SIZE_P     = CHUNK_SIZE + 2;

	inline constexpr int32 VOXELS_PER_CHUNK   = CHUNK_SIZE   * CHUNK_SIZE   * CHUNK_SIZE;
	inline constexpr int32 VOXELS_PER_CHUNK_P = CHUNK_SIZE_P * CHUNK_SIZE_P * CHUNK_SIZE_P;

	// World height in chunks (vertical). 8 chunks * 32 voxels = 256-voxel tall world.
	inline constexpr int32 WORLD_HEIGHT_CHUNKS = 8;
	inline constexpr int32 WORLD_HEIGHT_VOXELS = WORLD_HEIGHT_CHUNKS * CHUNK_SIZE;

	// One voxel in Unreal world units (centimetres). 100 uu = 1 m.
	inline constexpr float VOXEL_SIZE_UU = 100.0f;

	// Density iso-surface threshold. density > ISO_LEVEL => solid.
	inline constexpr int8 ISO_LEVEL = 0;

	// Default horizontal streaming radius, in chunks, around the viewer.
	inline constexpr int32 DEFAULT_VIEW_DISTANCE = 6;

	/** Flatten a padded (x,y,z) coordinate [0..CHUNK_SIZE_P) into a linear index. */
	FORCEINLINE int32 PaddedIndex(int32 X, int32 Y, int32 Z)
	{
		return X + Y * CHUNK_SIZE_P + Z * CHUNK_SIZE_P * CHUNK_SIZE_P;
	}
}
