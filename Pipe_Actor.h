// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Ball_TriggerBox.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pipe_Actor.generated.h"

UCLASS()
class AWHOLENEWBALLGAME_API APipe_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APipe_Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    UPROPERTY(EditAnywhere)
    class UStaticMeshComponent* Body;
    
    UPROPERTY(EditAnywhere)
    class ABall_TriggerBox* Ball_TriggerBox;

};
