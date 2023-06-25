// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InputAction.h"
#include "InputMappingContext.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Ball_Controller.generated.h"

/**
 * 
 */
UCLASS()
class AWHOLENEWBALLGAME_API ABall_Controller : public APlayerController
{
	GENERATED_BODY()
	
public:
    
    virtual void SetupInputComponent() override;
    
    //MappingContext for Ball_Pawn
    UPROPERTY()
    class UInputMappingContext* PawnMappingContext;
    
    UPROPERTY()
    class UInputAction* MoveAction;
};
