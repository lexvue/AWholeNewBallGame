// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball_Controller.h"


void ABall_Controller::SetupInputComponent() {
    Super::SetupInputComponent();
    
    PawnMappingContext = NewObject<UInputMappingContext>(this);
    
    MoveAction = NewObject<UInputAction>(this);
    MoveAction->ValueType = EInputActionValueType::Axis3D;
    PawnMappingContext->MapKey(MoveAction, EKeys::SpaceBar);
    
}
