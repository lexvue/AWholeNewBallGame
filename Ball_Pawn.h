// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/GameplayStatics.h"
#include "Ball_UserWidget.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Ball_Pawn.generated.h"

UCLASS()
class AWHOLENEWBALLGAME_API ABall_Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABall_Pawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    void MoveRight(const struct FInputActionValue& ActionValue);

    UPROPERTY(EditAnywhere)
    class USphereComponent* Sphere;
    
    UPROPERTY(EditAnywhere)
    class UStaticMeshComponent* Body;
    
    UPROPERTY(EditAnywhere)
    class USpringArmComponent* SpringArm;
    
    UPROPERTY(EditAnywhere)
    class UCameraComponent* Camera;
    
    UPROPERTY(EditAnywhere)
    class UFloatingPawnMovement* Movement;
    
    UPROPERTY(EditAnywhere)
    bool isConnectedToPole;
    
protected:
    UPROPERTY(BlueprintReadOnly, Category = "")
    int32 CurrentScore;

    UPROPERTY(EditDefaultsOnly, Category = "")
    TSubclassOf<UUserWidget> HUDClass;

    UPROPERTY(BlueprintReadOnly, Category = "")
    class UBall_UserWidget* HUD;

public:
    UFUNCTION(BlueprintPure, Category = "")
    int32 GetCurrentScore() const { return CurrentScore; }


    
};
