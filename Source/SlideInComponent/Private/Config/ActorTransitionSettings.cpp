// Copyright 2024 Josie Thompson, MIT License
#include "Config/ActorTransitionSettings.h"

const FTopLevelAssetPath UActorTransitionSettings::DefaultCurvePath{TEXT("/SlideInComponent/DefaultCurveLinearRamp")};

UActorTransitionSettings::UActorTransitionSettings()
{
    using FCurveFloatReference = ConstructorHelpers::FObjectFinder<UCurveFloat>;
    static FCurveFloatReference DefaultCurveLinearRamp{ *DefaultCurvePath.ToString() };
    if (DefaultCurve.IsNull()) {
        DefaultCurve = DefaultCurveLinearRamp.Object;
    }
}

UCurveFloat * UActorTransitionSettings::GetDefaultSlideInCurve()
{
    auto* Settings = GetMutableDefault<UActorTransitionSettings>();
    if (Settings->DefaultCurve.IsNull()) {
        Settings->DefaultCurve = FSoftObjectPath{DefaultCurvePath};
    }
    check(!Settings->DefaultCurve.IsNull());
    if (Settings->DefaultCurve.IsValid()) {
        return Settings->DefaultCurve.Get();
    }
    return Settings->DefaultCurve.LoadSynchronous();
}
