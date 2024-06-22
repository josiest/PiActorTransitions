// Copyright Epic Games, Inc. All Rights Reserved.
#include "Modules/ModuleManager.h"
#define LOCTEXT_NAMESPACE "FSlideInComponentModule"

class FSlideInComponentModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

void FSlideInComponentModule::StartupModule()
{
}

void FSlideInComponentModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSlideInComponentModule, SlideInComponent)