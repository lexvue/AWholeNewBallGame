// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball_Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Ball_Controller.h"
#include "Game/Framework/FloatingPawnMovement.h"


// Sets default values
ABall_Pawn::ABall_Pawn()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
   
    // Set this pawn to be controlled by the lowest-numbered player
    AutoPossessPlayer = EAutoReceiveInput::Player0;

    // Create components
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    PlayerShape =
        CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerShape"));
    
    // Attach our camera and visible object to our root component. Offset and rotate the camera.
    Camera->SetupAttachment(RootComponent);
    Camera->SetRelativeLocation(FVector(0.0f, 600.0f, 0.0f));
    Camera->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
    PlayerShape->SetupAttachment(RootComponent);
    
    Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
    

}

// Called when the game starts or when spawned
void ABall_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABall_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    UEnchancedInputComponent* EIC = Cast<UEnhancedInputController>(PlayerInputComponent);
    ABall_Controller* BC = Cast<ABall_Controller>(Controller);
    check (EIC && BC);
    EIC->BindAction(FPC->MoveAction, ETriggerEvent::Triggered, this, &ABall_Pawn::MoveRight);
    
    ULocalPlayer* LocalPlayer = FPC->GetLocalPlayer();
    check(LocalPlayer);
    UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
    check(Subsystem);
    Subsystem->ClearAllMappings();
    Subsystem->AddMappingContext(FPC->PawnMappingContext, 0);
}

void ABall_Pawn::MoveRight(const FInputActionValue& ActionValue) {
    FVector Input = ActionValue.Get<FInputActionValue::Axis3D>();
    AddMovementInput(GetActorRotation().RotateVector(Input), 1.0f);
}
