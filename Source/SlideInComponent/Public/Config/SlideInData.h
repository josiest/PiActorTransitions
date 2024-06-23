// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "Engine/DataAsset.h"
#include "SlideInData.generated.h"

/**
 * USlideInData
 *  Data used to configure a Slide-In component
 */
UCLASS(BlueprintType)
class PIACTORTRANSITIONS_API USlideInData : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    USlideInData();
    virtual EDataValidationResult IsDataValid(FDataValidationContext & Context) const override;
    
    /** The relative position the actor will slide in From */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General")
    FVector SlideFromOffset;

    /** The time it takes to slide in */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General", meta=(ClampMin=0.01))
    float SlideInTime = 1.f;

    /** The Curve the slide-in follows */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General")
    TObjectPtr<UCurveFloat> SlideInCurve;
};
