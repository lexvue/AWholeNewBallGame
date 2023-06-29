// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "Ball_Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Ball_TriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class AWHOLENEWBALLGAME_API ABall_TriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
protected:
    virtual void BeginPlay() override;

public:
    ABall_TriggerBox();

    UFUNCTION()
    void ConnectToPole(class AActor* OverlappedActor, class AActor* OtherActor);
    void DisconnectFromPole(class AActor* OverlappedActor, class AActor* OtherActor);
};
