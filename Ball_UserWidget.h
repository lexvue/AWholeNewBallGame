// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Ball_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AWHOLENEWBALLGAME_API UBall_UserWidget : public UUserWidget
{

    GENERATED_BODY()

protected:
    UFUNCTION(BlueprintImplementableEvent, Category = "")
    void OnCurrentScoreChanged(const FText& NewScoreText);

public:
    UBall_UserWidget(const FObjectInitializer& ObjectInitializer);

    void OnGetCoin(int32 CurrentScore);



};
