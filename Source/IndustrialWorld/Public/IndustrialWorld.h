// Copyright MindblownDK. IndustrialWorld — UE 5.7.4 rebuild.
#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/**
 * Primary runtime module for IndustrialWorld.
 * All gameplay domains (Core, Generation, Meshing, Building, ...) live in this
 * single module, separated by folder to mirror the original Unity architecture.
 */
class FIndustrialWorldModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

/** Engine-wide log category for the IndustrialWorld game. */
DECLARE_LOG_CATEGORY_EXTERN(LogIndustrialWorld, Log, All);
