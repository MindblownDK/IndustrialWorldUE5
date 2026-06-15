// Copyright MindblownDK. IndustrialWorld — UE 5.7.4 rebuild.
#include "IndustrialWorld.h"
#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY(LogIndustrialWorld);

void FIndustrialWorldModule::StartupModule()
{
	UE_LOG(LogIndustrialWorld, Log, TEXT("IndustrialWorld module started (UE 5.7.4 rebuild)."));
}

void FIndustrialWorldModule::ShutdownModule()
{
	UE_LOG(LogIndustrialWorld, Log, TEXT("IndustrialWorld module shut down."));
}

IMPLEMENT_PRIMARY_GAME_MODULE(FIndustrialWorldModule, IndustrialWorld, "IndustrialWorld");
