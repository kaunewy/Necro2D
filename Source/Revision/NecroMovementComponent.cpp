// Fill out your copyright notice in the Description page of Project Settings.


#include "NecroMovementComponent.h"
#include "Necro.h"

// Sets default values for this component's properties
UNecroMovementComponent::UNecroMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UNecroMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	owner = Cast<ANecro>(GetOwner());
	// ...
	
}


// Called every frame
void UNecroMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UNecroMovementComponent::Move(const FInputActionValue& _value)
{
	float _moveValue = _value.Get<float>();

	owner->AddMovementInput(owner->GetActorForwardVector(), _moveValue);

	onMovement.Broadcast(_moveValue);
}

