// Copyright 2024 Josie Thompson, MIT License
#include "SlideInSettings.h"

const FTopLevelAssetPath USlideInSettings::DefaultCurvePath{TEXT("/SlideInComponent/DefaultCurveLinearRamp")};

USlideInSettings::USlideInSettings()
{
    using FCurveFloatReference = ConstructorHelpers::FObjectFinder<UCurveFloat>;
    static FCurveFloatReference DefaultCurveLinearRamp{ *DefaultCurvePath.ToString() };
    if (DefaultCurve.IsNull()) {
        DefaultCurve = DefaultCurveLinearRamp.Object;
    }
}

UCurveFloat * USlideInSettings::GetDefaultSlideInCurve()
{
    auto* Settings = GetMutableDefault<USlideInSettings>();
    if (Settings->DefaultCurve.IsNull()) {
        Settings->DefaultCurve = FSoftObjectPath{DefaultCurvePath};
    }
    check(!Settings->DefaultCurve.IsNull());
    if (Settings->DefaultCurve.IsValid()) {
        return Settings->DefaultCurve.Get();
    }
    return Settings->DefaultCurve.LoadSynchronous();
}
