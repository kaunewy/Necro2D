// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include <Kismet/KismetSystemLibrary.h>

AEnemy::AEnemy()
{
	attackCompo = CreateDefaultSubobject<UAttackComponent>("AttackComponent");
	triggerBox = CreateDefaultSubobject<UBoxComponent>("TriggerBox");
	healthCompo = CreateDefaultSubobject<UHealthComponent>("HealthComponent");

	AddOwnedComponent(attackCompo);
	AddOwnedComponent(triggerBox);
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
	UKismetSystemLibrary::PrintString(this, "Enemy touch the player");
}

