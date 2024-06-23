// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "Components/ActorComponent.h"
#include "Components/TimelineComponent.h"
#include "SlideInComponent.generated.h"

class USlideInData;

/**
 * USlideInComponent
 *  A component that manages a really simple slide-in animation.
 */
UCLASS(Blueprintable, meta=(BlueprintSpawnableComponent))
class SLIDEINCOMPONENT_API USlideInComponent : public UActorComponent {
    GENERATED_BODY()

public:
    USlideInComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    // Actor Component Interface
    virtual void InitializeComponent() override;

    /** Play the slide-in animation */
    UFUNCTION(BlueprintCallable)
    void SlideIn() const;

    /** The configuration data for the slide-in animation */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="General")
    TObjectPtr<USlideInData> SlideInData;

protected:
    /** Define how the actor updates its transform */
    UFUNCTION(BlueprintNativeEvent)
    void UpdatePosition(float Alpha);

private:
    /** The timeline that animates the alpha lerping variable */
    UPROPERTY(Transient)
    TObjectPtr<UTimelineComponent> Timeline;

    /** The cached actor position to slide from */
    UPROPERTY(Transient)
    FVector SlideFromPosition;

    /** The cached actor position to slide to */
    UPROPERTY(Transient)
    FVector SlideToPosition;

    /** Delegate handle to bind UpdatePosition with */
    UPROPERTY(Transient)
    FOnTimelineFloat OnUpdateTimeline;
};
