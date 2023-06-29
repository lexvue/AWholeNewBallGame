#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))


#include "Ball_TriggerBox.h"

ABall_TriggerBox::ABall_TriggerBox() {

    OnActorBeginOverlap.AddDynamic(this, &ABall_TriggerBox::ConnectToPole);
    OnActorEndOverlap.AddDynamic(this, &ABall_TriggerBox::DisconnectFromPole);
}

void ABall_TriggerBox::BeginPlay() {
    Super::BeginPlay();
}

void ABall_TriggerBox::ConnectToPole(class AActor* OverlappedActor, class AActor* OtherActor) {
    print("Overlap Begin");
    if (OtherActor && (OtherActor != this)) {
        ABall_Pawn* Player = Cast<ABall_Pawn>(OtherActor);
        if (!Player->isConnectedToPole) {
            Player->isConnectedToPole = true;
            Player->SetActorLocation(this->GetActorLocation());
        }
    }
}

void ABall_TriggerBox::DisconnectFromPole(class AActor* OverlappedActor, class AActor* OtherActor) {
    print("Overlap Ended");
    if (OtherActor && (OtherActor != this)) {
        ABall_Pawn* Player = Cast<ABall_Pawn>(OtherActor);
        if (Player->isConnectedToPole) {
            Player->isConnectedToPole = false;
        }
    }
}
