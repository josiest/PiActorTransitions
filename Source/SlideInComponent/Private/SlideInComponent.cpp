// Copyright 2024 Josie Thompson, MIT License
#include "SlideInComponent.h"
#include "SlideInData.h"
#include "Components/TimelineComponent.h"

USlideInComponent::USlideInComponent(const FObjectInitializer& ObjectInitializer)
    : Super{ ObjectInitializer }
{
    bWantsInitializeComponent = true;
    Timeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Timeline"));
}

void USlideInComponent::InitializeComponent()
{
    OnUpdateTimeline.BindDynamic(this, &ThisClass::UpdatePosition);
    SlideToPosition = GetOwner()->GetActorLocation();

    if (!ensure(SlideInData)) { return; }
    Timeline->AddInterpFloat(SlideInData->SlideInCurve, OnUpdateTimeline,
                             TEXT("Alpha"), TEXT("SlideIn"));
    Timeline->SetPlayRate(SlideInData->SlideInTime == 0.f?
                          0.f : 1.f/SlideInData->SlideInTime);
    SlideFromPosition = SlideToPosition + SlideInData->SlideFromOffset;
}

void USlideInComponent::SlideIn() const
{
    Timeline->PlayFromStart();
}

void USlideInComponent::UpdatePosition_Implementation(float Alpha)
{
    const auto NewLocation = FMath::Lerp(SlideFromPosition, SlideToPosition, Alpha);
    GetOwner()->SetActorRelativeLocation(NewLocation);
}
