// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "Components/TimelineComponent.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncAction_SlideInActor.generated.h"

class USlideInData;
/**
 * UAsyncAction_SlideInActor
 *  Play an animation that slides an actor in from another position
 */
UCLASS()
class PIACTORTRANSITIONS_API UAsyncAction_SlideInActor : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="Actor Transitions", meta=(WorldContext="WorldContext"))
    static UAsyncAction_SlideInActor *
    SlideInActor(const UObject* WorldContext, AActor* ActorToSlideIn, FVector SlideInOffset,
                 UCurveFloat* SlideInCurve, float PlaybackSpeed);

    UFUNCTION(BlueprintCallable, Category="Actor Transitions", meta=(WorldContext="WorldContext"))
    static UAsyncAction_SlideInActor *
    SlideInActorFromData(const UObject * WorldContext, AActor * ActorToSlideIn, const USlideInData* SlideInData);

    // Async Action interface
    virtual void Activate() override;
    
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAnimationFinished);

    /** Do something when the animation finishes */
    UPROPERTY(BlueprintAssignable)
    FOnAnimationFinished OnFinished;
protected:

    /** Handle what happens when the slide-in animation finishes */
    UFUNCTION()
    virtual void HandleAnimationFinished();

    /** Handle what happens when the slide-in animation updates */
    UFUNCTION()
    virtual void HandleAnimationUpdate(float Alpha);

    /** The cached actor to move */
    UPROPERTY(Transient)
    AActor* ActorToSlide;
    
    /** The cached actor position to slide from */
    UPROPERTY(Transient)
    FVector SlideFromPosition;

    /** The cached actor position to slide to */
    UPROPERTY(Transient)
    FVector SlideToPosition;
    
private:
    /** The timeline that animates the alpha lerping variable */
    UPROPERTY(Transient)
    TObjectPtr<UTimelineComponent> Timeline;

    /** Delegate handle to bind UpdatePosition with */
    UPROPERTY(Transient)
    FOnTimelineFloat OnUpdateTimeline;

    /** Delegate handle to bind HandleTimelineFinished */
    UPROPERTY(Transient)
    FOnTimelineEvent OnTimelineFinished;
};
