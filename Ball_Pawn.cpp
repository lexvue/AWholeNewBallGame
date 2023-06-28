// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball_Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Ball_Controller.h"
#include "GameFramework/PawnMovementComponent.h"



// Sets default values
ABall_Pawn::ABall_Pawn()
{
    
    Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
    SetRootComponent(Sphere);
    
    Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
    Body->SetupAttachment(Sphere);
    
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(Sphere);
    
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    
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

    UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    ABall_Controller* BC = Cast<ABall_Controller>(Controller);
    check (EIC && BC);
    EIC->BindAction(BC->MoveAction, ETriggerEvent::Started, this, &ABall_Pawn::MoveRight);
    
    ULocalPlayer* LocalPlayer = BC->GetLocalPlayer();
    check(LocalPlayer);
    UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
    check(Subsystem);
    Subsystem->ClearAllMappings();
    Subsystem->AddMappingContext(BC->PawnMappingContext, 0);
}

void ABall_Pawn::MoveRight(const FInputActionValue& ActionValue) {
    FVector Input = ActionValue.Get<FInputActionValue::Axis3D>();
    AddMovementInput(GetActorRotation().RotateVector(Input), 1.0f);
}


