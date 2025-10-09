// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/CapsuleComponent.h"
#include "Necro.h"
#include <Kismet/KismetSystemLibrary.h>

AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	attackCompo = CreateDefaultSubobject<UAttackComponent>("AttackComponent");
	triggerBox = CreateDefaultSubobject<UBoxComponent>("TriggerBox");
	healthCompo = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
	moveCompo = CreateDefaultSubobject<UEnemyMovementComponent>("MoveCompo");
	sprite = CreateDefaultSubobject<UPaperFlipbookComponent>("Sprite");
	capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	animCompo = CreateDefaultSubobject<UPaperZDAnimationComponent>("AnimCompo");

	RootComponent = capsule;         
	AddOwnedComponent(attackCompo);
	triggerBox->SetupAttachment(GetCapsuleComponent());
	sprite->SetupAttachment(GetCapsuleComponent());
	AddOwnedComponent(moveCompo);
	AddOwnedComponent(animCompo);
}


void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void AEnemy::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);
	if (canAttack && !isAttacking)
	{
		attackCompo->AttackWithoutBind(player);
		attackCompo->GetOnAttack().Broadcast(true);
	}
}

void AEnemy::Init()
{
	triggerBox->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::BeginOverlap);
	triggerBox->OnComponentEndOverlap.AddDynamic(this, &AEnemy::OnEndOverlap);
}



void AEnemy::BeginOverlap(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	player = OtherActor;
	canAttack = true;
}

void AEnemy::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	player = nullptr;
	canAttack = false;
	attackCompo->GetOnAttack().Broadcast(false);
}

