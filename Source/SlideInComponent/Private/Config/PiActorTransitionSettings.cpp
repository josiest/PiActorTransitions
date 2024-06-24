// Copyright 2024 Josie Thompson, MIT License
#include "Config/PiActorTransitionSettings.h"

#include "Config/PiSlideInData.h"

const FTopLevelAssetPath UPiActorTransitionSettings::DefaultCurvePath{
    TEXT("/PiActorTransitions/DefaultCurveLinearRamp")
};
const FTopLevelAssetPath UPiActorTransitionSettings::DefaultSlideInDataPath{
    TEXT("/PiActorTransitions/SLIDE_DefaultSlideIn")
};

UPiActorTransitionSettings::UPiActorTransitionSettings()
{
    using FCurveFloatReference = ConstructorHelpers::FObjectFinder<UCurveFloat>;
    static FCurveFloatReference DefaultCurveLinearRamp{ *DefaultCurvePath.ToString() };
    if (DefaultCurve.IsNull()) {
        DefaultCurve = DefaultCurveLinearRamp.Object;
    }
    using FSlideInDataReference = ConstructorHelpers::FObjectFinder<UPiSlideInData>;
    static FSlideInDataReference DefaultSlideInReference{ *DefaultSlideInDataPath.ToString() };
    if (DefaultSlideInData.IsNull()) {
        DefaultSlideInData = DefaultSlideInReference.Object;
    }
}

UCurveFloat * UPiActorTransitionSettings::GetDefaultSlideInCurve()
{
    auto* Settings = GetMutableDefault<UPiActorTransitionSettings>();
    if (Settings->DefaultCurve.IsNull()) {
        Settings->DefaultCurve = FSoftObjectPath{DefaultCurvePath};
    }
    check(!Settings->DefaultCurve.IsNull());
    if (Settings->DefaultCurve.IsValid()) {
        return Settings->DefaultCurve.Get();
    }
    return Settings->DefaultCurve.LoadSynchronous();
}

UPiSlideInData * UPiActorTransitionSettings::GetDefaultSlideInData()
{
    auto* Settings = GetMutableDefault<UPiActorTransitionSettings>();
    if (Settings->DefaultSlideInData.IsNull()) {
        Settings->DefaultSlideInData = FSoftObjectPath{DefaultSlideInDataPath};
    }
    check(!Settings->DefaultSlideInData.IsNull());
    if (Settings->DefaultSlideInData.IsValid()) {
        return Settings->DefaultSlideInData.Get();
    }
    return Settings->DefaultSlideInData.LoadSynchronous();
}

