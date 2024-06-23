// Copyright 2024 Josie Thompson, MIT License


#include "ActorTransitions/AsyncAction_SlideInActor.h"
#include "Config/SlideInData.h"

UAsyncAction_SlideInActor *
UAsyncAction_SlideInActor::SlideInActor(const UObject * WorldContext, AActor * ActorToSlideIn,
                                        FVector SlideInOffset, UCurveFloat * SlideInCurve, float PlaybackSpeed)
{
    auto* Action = NewObject<UAsyncAction_SlideInActor>();
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

UAsyncAction_SlideInActor *
UAsyncAction_SlideInActor::SlideInActorFromData(const UObject * WorldContext, AActor * ActorToSlideIn,
                                                const USlideInData * SlideInData)
{
    return SlideInActor(WorldContext, ActorToSlideIn,
                        SlideInData->SlideFromOffset, SlideInData->SlideInCurve,
                        SlideInData->SlideInTime != 0.f? 1.f/SlideInData->SlideInTime : 0.f);
}

void UAsyncAction_SlideInActor::Activate()
{
    Timeline->PlayFromStart();
}

void UAsyncAction_SlideInActor::HandleAnimationUpdate(float Alpha)
{
    const auto NewLocation = FMath::Lerp(SlideFromPosition, SlideToPosition, Alpha);
    ActorToSlide->SetActorRelativeLocation(NewLocation);
}

void UAsyncAction_SlideInActor::HandleAnimationFinished()
{
    OnFinished.Broadcast();
}
