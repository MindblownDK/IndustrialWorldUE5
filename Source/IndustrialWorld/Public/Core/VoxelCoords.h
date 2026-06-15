// Copyright MindblownDK. IndustrialWorld — UE 5.7.4 rebuild.
//
// Lightweight integer coordinate helpers shared by the voxel engine.
// FIntVector is used for chunk coordinates; these free functions convert
// between world (uu), voxel, and chunk spaces consistently everywhere.
#pragma once

#include "CoreMinimal.h"
#include "Core/VoxelConstants.h"

namespace VoxelCoords
{
	/** Floor-divide that works correctly for negative numerators. */
	FORCEINLINE int32 FloorDiv(int32 A, int32 B)
	{
		const int32 Q = A / B;
		const int32 R = A % B;
		return (R != 0 && ((R < 0) != (B < 0))) ? Q - 1 : Q;
	}

	/** Positive modulo (result always in [0, B)). */
	FORCEINLINE int32 PosMod(int32 A, int32 B)
	{
		const int32 R = A % B;
		return (R < 0) ? R + B : R;
	}

	/** World location (uu) -> integer voxel coordinate. */
	FORCEINLINE FIntVector WorldToVoxel(const FVector& World)
	{
		return FIntVector(
			FMath::FloorToInt(World.X / VoxelConstants::VOXEL_SIZE_UU),
			FMath::FloorToInt(World.Y / VoxelConstants::VOXEL_SIZE_UU),
			FMath::FloorToInt(World.Z / VoxelConstants::VOXEL_SIZE_UU));
	}

	/** Integer voxel coordinate -> world location (uu) at the voxel's min corner. */
	FORCEINLINE FVector VoxelToWorld(const FIntVector& Voxel)
	{
		return FVector(
			Voxel.X * VoxelConstants::VOXEL_SIZE_UU,
			Voxel.Y * VoxelConstants::VOXEL_SIZE_UU,
			Voxel.Z * VoxelConstants::VOXEL_SIZE_UU);
	}

	/** Voxel coordinate -> owning chunk coordinate. */
	FORCEINLINE FIntVector VoxelToChunk(const FIntVector& Voxel)
	{
		return FIntVector(
			FloorDiv(Voxel.X, VoxelConstants::CHUNK_SIZE),
			FloorDiv(Voxel.Y, VoxelConstants::CHUNK_SIZE),
			FloorDiv(Voxel.Z, VoxelConstants::CHUNK_SIZE));
	}

	/** Local voxel coordinate within its chunk (each component in [0, CHUNK_SIZE)). */
	FORCEINLINE FIntVector VoxelToLocal(const FIntVector& Voxel)
	{
		return FIntVector(
			PosMod(Voxel.X, VoxelConstants::CHUNK_SIZE),
			PosMod(Voxel.Y, VoxelConstants::CHUNK_SIZE),
			PosMod(Voxel.Z, VoxelConstants::CHUNK_SIZE));
	}

	/** Chunk coordinate -> world-space origin (uu) of the chunk's (0,0,0) voxel. */
	FORCEINLINE FVector ChunkToWorldOrigin(const FIntVector& Chunk)
	{
		return FVector(
			Chunk.X * VoxelConstants::CHUNK_SIZE * VoxelConstants::VOXEL_SIZE_UU,
			Chunk.Y * VoxelConstants::CHUNK_SIZE * VoxelConstants::VOXEL_SIZE_UU,
			Chunk.Z * VoxelConstants::CHUNK_SIZE * VoxelConstants::VOXEL_SIZE_UU);
	}
}
