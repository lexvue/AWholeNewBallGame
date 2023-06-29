// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball_UserWidget.h"

UBall_UserWidget::UBall_UserWidget(const FObjectInitializer&
ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UBall_UserWidget::OnGetCoin(int32 CurrentScore) {
    FText CurrentScoreText = FText::FromString(FString("Score: " + FString::FromInt(CurrentScore)));
    OnCurrentScoreChanged(CurrentScoreText);
}
