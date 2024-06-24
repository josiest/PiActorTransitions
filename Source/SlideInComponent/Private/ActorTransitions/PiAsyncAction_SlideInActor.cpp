// Copyright 2024 Josie Thompson, MIT License


#include "ActorTransitions/PiAsyncAction_SlideInActor.h"
#include "Config/PiSlideInData.h"

UPiAsyncAction_SlideInActor *
UPiAsyncAction_SlideInActor::SlideInActor(const UObject * WorldContext, AActor * ActorToSlideIn,
                                          FVector SlideInOffset, UCurveFloat * SlideInCurve, float PlaybackSpeed)
{
    auto* Action = NewObject<UPiAsyncAction_SlideInActor>();
    Action->ActorToSlide = ActorToSlideIn;
    Action->Timeline = NewObject<UTimelineComponent>();
    Action->Timeline->RegisterComponentWithWorld(WorldContext->GetWorld());
    
    Action->OnUpdateTimeline.BindDynamic(Action, &ThisClass::HandleAnimationUpdate);
    Action->Timeline->AddInterpFloat(SlideInCurve, Action->OnUpdateTimeline,
                                     TEXT("Alpha"), TEXT("SlideIn"));
    Action->Timeline->SetPlayRate(PlaybackSpeed);

    Action->OnTimelineFinished.BindDynamic(Action, &ThisClass::HandleAnimationFinished);
    Action->Timeline->SetTimelineFinishedFunc(Action->OnTimelineFinished);

    Action->SlideToPosition = ActorToSlideIn->GetActorLocation();
    Action->SlideFromPosition = Action->SlideToPosition + SlideInOffset;
    return Action;
}

UPiAsyncAction_SlideInActor *
UPiAsyncAction_SlideInActor::SlideInActorFromData(const UObject * WorldContext, AActor * ActorToSlideIn,
                                                  const UPiSlideInData * SlideInData)
{
    return SlideInActor(WorldContext, ActorToSlideIn,
                        SlideInData->SlideFromOffset, SlideInData->SlideInCurve,
                        SlideInData->SlideInTime != 0.f? 1.f/SlideInData->SlideInTime : 0.f);
}

void UPiAsyncAction_SlideInActor::Activate()
{
    Timeline->PlayFromStart();
}

void UPiAsyncAction_SlideInActor::HandleAnimationUpdate(float Alpha)
{
    const auto NewLocation = FMath::Lerp(SlideFromPosition, SlideToPosition, Alpha);
    ActorToSlide->SetActorRelativeLocation(NewLocation);
}

void UPiAsyncAction_SlideInActor::HandleAnimationFinished()
{
    OnFinished.Broadcast();
}
