// Fill out your copyright notice in the Description page of Project Settings.


#include "Necro.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <Kismet/KismetSystemLibrary.h>

ANecro::ANecro()
{

	movementCompo = CreateDefaultSubobject<UNecroMovementComponent>("Movement");
	attackCompo = CreateDefaultSubobject<UAttackComponent>("Attack");
	triggerBox = CreateDefaultSubobject<UBoxComponent>("TriggerBox");
	healthCompo = CreateDefaultSubobject<UHealthComponent>("HealthCompo");

	AddOwnedComponent(movementCompo);
	AddOwnedComponent(attackCompo);
	AddOwnedComponent(healthCompo);
	triggerBox->SetupAttachment(RootComponent);
}

void ANecro::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void ANecro::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);
	if (canAttack)
	{
		attackCompo->AttackWithoutBind(_enemy);
	}
}

void ANecro::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* _compo = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!_compo) return;
	_compo->BindAction(_inputs._inputMap[EInputTypes::MOVE], ETriggerEvent::Triggered, movementCompo.Get(), &UNecroMovementComponent::Move);
	_compo->BindAction(_inputs._inputMap[EInputTypes::MOVE], ETriggerEvent::Completed, movementCompo.Get(), &UNecroMovementComponent::Move);
	_compo->BindAction(_inputs._inputMap[EInputTypes::JUMP], ETriggerEvent::Triggered, this, &ANecro::Jump);
	_compo->BindAction(_inputs._inputMap[EInputTypes::ATTACK], ETriggerEvent::Triggered, attackCompo.Get(), &UAttackComponent::Attack);
}

void ANecro::Init()
{
	ULocalPlayer* _localPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	UEnhancedInputLocalPlayerSubsystem* _sys = _localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	_sys->AddMappingContext(_inputs._mappingContext, 0);

	triggerBox->OnComponentBeginOverlap.AddDynamic(this, &ANecro::OnBeginOverlap);
}

void ANecro::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	_enemy = OtherActor;
}
