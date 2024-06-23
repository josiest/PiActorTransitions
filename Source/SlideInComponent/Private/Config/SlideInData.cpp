// Copyright 2024 Josie Thompson, MIT License
#include "Config/SlideInData.h"
#include "Config/ActorTransitionSettings.h"
#include "Misc/DataValidation.h"

#define LOCTEXT_NAMESPACE "SlideInData"

USlideInData::USlideInData()
{
    if (!SlideInCurve) {
        SlideInCurve = UActorTransitionSettings::GetDefaultSlideInCurve();
    }
}

EDataValidationResult USlideInData::IsDataValid(FDataValidationContext & Context) const
{
    auto IsValidResult = EDataValidationResult::Valid;
    if (!IsValid(SlideInCurve)) {
        Context.AddError(FText::Format(LOCTEXT("SlideInCurve_Invalid", "Slide in curve in {0} is invalid"),
                                       FText::FromString(GetNameSafe(this))));
        IsValidResult = EDataValidationResult::Invalid;
    }
    if (SlideInTime <= 0.f) {
        Context.AddError(FText::Format(LOCTEXT("SlideInTime_Invalid", "Slide in time in {0} must be positive"),
                                       FText::FromString(GetNameSafe(this))));
        IsValidResult = EDataValidationResult::Invalid;
    }
    return CombineDataValidationResults(IsValidResult, Super::IsDataValid(Context));
}

#undef LOCTEXT_NAMESPACE