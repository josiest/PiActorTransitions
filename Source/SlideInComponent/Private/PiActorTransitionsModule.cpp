// Copyright Epic Games, Inc. All Rights Reserved.
#include "Modules/ModuleManager.h"
#define LOCTEXT_NAMESPACE "FPiActorTransitionsModule"

class FPiActorTransitionsModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

void FPiActorTransitionsModule::StartupModule()
{
}

void FPiActorTransitionsModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPiActorTransitionsModule, PiActorTransitions)