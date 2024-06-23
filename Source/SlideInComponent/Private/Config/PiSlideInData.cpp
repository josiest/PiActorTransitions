// Copyright 2024 Josie Thompson, MIT License
#include "Config/PiSlideInData.h"
#include "Config/PiActorTransitionSettings.h"
#include "Misc/DataValidation.h"

#define LOCTEXT_NAMESPACE "SlideInData"

UPiSlideInData::UPiSlideInData()
{
    if (!SlideInCurve) {
        SlideInCurve = UPiActorTransitionSettings::GetDefaultSlideInCurve();
    }
}

EDataValidationResult UPiSlideInData::IsDataValid(FDataValidationContext & Context) const
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