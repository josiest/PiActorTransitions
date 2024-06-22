// Copyright 2024 Josie Thompson, MIT License
#pragma once
#include "Engine/DeveloperSettings.h"
#include "SlideInSettings.generated.h"

/**
 * USlideInSettings
 *  Settings for the Slide-in Component plugin
 */
UCLASS(Config=Game)
class SLIDEINCOMPONENT_API USlideInSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    USlideInSettings();

    static UCurveFloat* GetDefaultSlideInCurve();

    static const FTopLevelAssetPath DefaultCurvePath;
    
    UPROPERTY(Config, EditDefaultsOnly, BlueprintReadOnly, Category="Data")
    TSoftObjectPtr<UCurveFloat> DefaultCurve;
};
