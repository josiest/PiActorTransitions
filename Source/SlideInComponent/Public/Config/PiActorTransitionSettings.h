// Copyright 2024 Josie Thompson, MIT License
#pragma once
#include "Engine/DeveloperSettings.h"
#include "PiActorTransitionSettings.generated.h"

class UPiSlideInData;

/**
 * USlideInSettings
 *  Settings for the Slide-in Component plugin
 */
UCLASS(Config=Game)
class PIACTORTRANSITIONS_API UPiActorTransitionSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPiActorTransitionSettings();

    static UCurveFloat* GetDefaultSlideInCurve();
    static UPiSlideInData* GetDefaultSlideInData();

    static const FTopLevelAssetPath DefaultCurvePath;
    static const FTopLevelAssetPath DefaultSlideInDataPath;
    
    UPROPERTY(Config, EditDefaultsOnly, BlueprintReadOnly, Category="Data")
    TSoftObjectPtr<UCurveFloat> DefaultCurve;

    UPROPERTY(Config, EditDefaultsOnly, BlueprintReadOnly, Category="Data")
    TSoftObjectPtr<UPiSlideInData> DefaultSlideInData;
};