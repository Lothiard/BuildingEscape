// Copyright János Restye 2024.


#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// FString ObjectRotation = GetOwner()->GetTransform().GetRotation().ToString();
	// UE_LOG(LogTemp, Error, TEXT("Door's rotation = %s"), *ObjectRotation);

}

void UOpenDoor::OpenDoor() {
	AActor* Owner = GetOwner();

	FRotator NewRotation = FRotator(0, 40, 0);

	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens)) { // If the ActorThatOpens is in the volume
		OpenDoor();
	}
	
}
