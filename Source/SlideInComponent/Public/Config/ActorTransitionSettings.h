// Copyright 2024 Josie Thompson, MIT License
#pragma once
#include "Engine/DeveloperSettings.h"
#include "ActorTransitionSettings.generated.h"

/**
 * USlideInSettings
 *  Settings for the Slide-in Component plugin
 */
UCLASS(Config=Game)
class PIACTORTRANSITIONS_API UActorTransitionSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UActorTransitionSettings();

    static UCurveFloat* GetDefaultSlideInCurve();

    static const FTopLevelAssetPath DefaultCurvePath;
    
    UPROPERTY(Config, EditDefaultsOnly, BlueprintReadOnly, Category="Data")
    TSoftObjectPtr<UCurveFloat> DefaultCurve;
};
