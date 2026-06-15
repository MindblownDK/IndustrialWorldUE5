// Copyright MindblownDK. IndustrialWorld — UE 5.7.4 rebuild.
#include "Core/Voxel.h"

const FVoxel FVoxel::Empty = FVoxel(-127, static_cast<uint8>(EVoxelMaterial::Air), 0);
const FVoxel FVoxel::Solid = FVoxel(127,  static_cast<uint8>(EVoxelMaterial::Stone), 0);
