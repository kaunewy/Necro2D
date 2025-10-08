// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/CapsuleComponent.h"
#include <Kismet/KismetSystemLibrary.h>

AEnemy::AEnemy()
{
	attackCompo = CreateDefaultSubobject<UAttackComponent>("AttackComponent");
	triggerBox = CreateDefaultSubobject<UBoxComponent>("TriggerBox");
	healthCompo = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
	moveCompo = CreateDefaultSubobject<UEnemyMovementComponent>("MoveCompo");
	sprite = CreateDefaultSubobject<UPaperFlipbookComponent>("Sprite");
	capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");

	AddOwnedComponent(attackCompo);
	triggerBox->SetupAttachment(GetCapsuleComponent());
	sprite->SetupAttachment(GetCapsuleComponent());
	AddOwnedComponent(moveCompo);
	RootComponent = capsule;
}


void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void AEnemy::Init()
{
	triggerBox->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::BeginOverlap);
}

void AEnemy::BeginOverlap(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	attackCompo->AttackWithoutBind(OtherActor);
	UKismetSystemLibrary::PrintString(this, "Enemy touch the player");
}

