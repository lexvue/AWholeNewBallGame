// Fill out your copyright notice in the Description page of Project Settings.


#include "Pipe_Actor.h"

// Sets default values
APipe_Actor::APipe_Actor()
{
    Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
    SetRootComponent(Body);
    
    Ball_TriggerBox = CreateDefaultSubobject<ABall_TriggerBox>(TEXT("Ball_TriggerBox"));
    Ball_TriggerBox->AttachToComponent(Body, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
    

}

// Called when the game starts or when spawned
void APipe_Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APipe_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

