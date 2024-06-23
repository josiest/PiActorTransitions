// Copyright 2024 Josie Thompson, MIT License
#include "Config/PiActorTransitionSettings.h"

const FTopLevelAssetPath UPiActorTransitionSettings::DefaultCurvePath{TEXT("/PiActorTransitions/DefaultCurveLinearRamp")};

UPiActorTransitionSettings::UPiActorTransitionSettings()
{
    using FCurveFloatReference = ConstructorHelpers::FObjectFinder<UCurveFloat>;
    static FCurveFloatReference DefaultCurveLinearRamp{ *DefaultCurvePath.ToString() };
    if (DefaultCurve.IsNull()) {
        DefaultCurve = DefaultCurveLinearRamp.Object;
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
