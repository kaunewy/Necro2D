// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyMovementComponent.h"
#include "Enemy.h"
#include "Components/CapsuleComponent.h"
#include <Kismet/KismetSystemLibrary.h>

// Sets default values for this component's properties
UEnemyMovementComponent::UEnemyMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
	// ...
	
}


// Called every frame
void UEnemyMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Move();
	// ...
}

void UEnemyMovementComponent::Init()
{
	owner = Cast<AEnemy>(GetOwner());
	//owner->GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &UEnemyMovementComponent::EnemyHitWall);
}

void UEnemyMovementComponent::Move()
{
	if (!canMove)
	{
		return;
	}
	FHitResult _hit;
	owner->GetCapsuleComponent()->MoveComponent(direction * speed * GetWorld()->DeltaTimeSeconds, owner->GetActorRotation(), true, &_hit);

	if (_hit.bBlockingHit)
	{
		owner->AddActorLocalRotation(FRotator(0, 180, 0));
		direction *= -1.0f;
		UKismetSystemLibrary::PrintString(this, "touch something");
	}
}

//void UEnemyMovementComponent::EnemyHitWall(UPrimitiveComponent* HitComponent,
//	AActor* OtherActor,
//	UPrimitiveComponent* OtherComp,
//	FVector NormalImpulse,
//	const FHitResult& Hit)
//{
//	FVector _impactNormal = Hit.ImpactNormal;
//
//	FVector _direction = FVector(direction, 0, 0);
//
//	float _dotUp = FVector::DotProduct(_impactNormal, FVector::UpVector);
//
//	if (_dotUp > 0.8f)
//	{
//		return;
//	}
//	
//	float _dotForward = FVector::DotProduct(_impactNormal, _direction);
//	if (_dotForward > 0.1)
//	{
//		return;
//	}
//
//	UKismetSystemLibrary::PrintString(this, FString::SanitizeFloat(_dotForward));
//	UKismetSystemLibrary::PrintString(this, OtherActor->GetActorNameOrLabel());
//
//	owner->AddActorLocalRotation(FRotator(0, 180, 0));
//	direction *= -1.0f;
//	UKismetSystemLibrary::PrintString(this, "touch something");
//}

