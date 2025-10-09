// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackComponent.h"
#include "Necro.h"
#include "Enemy.h"
#include "HealthComponent.h"
#include <Kismet/KismetSystemLibrary.h>

// Sets default values for this component's properties
UAttackComponent::UAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAttackComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
	// ...
	
}


// Called every frame
void UAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAttackComponent::Attack(const FInputActionValue& _value)
{
	const bool& _val = _value.Get<bool>();

	onAttack.Broadcast(_val);

}


void UAttackComponent::AttackWithoutBind(AActor* _otherActor)
{

	//onAttack.Broadcast(true);

	ANecro* _necro = Cast<ANecro>(_otherActor);
	if (_necro)
	{
		UKismetSystemLibrary::PrintString(this, "player take damage");
		_necro->GetHealthComponent()->TakeDamage(1.0f);
		AEnemy* _enemy = Cast<AEnemy>(owner);
		if (_enemy)
		{
			_enemy->SetCanAttack(false);
		}
	}
	else
	{
		AEnemy* _enemy = Cast<AEnemy>(_otherActor);
		if (!_enemy)
		{
			return;
		}
		_enemy->GetHealthComponent()->TakeDamage(1.0f);
		ANecro* _player = Cast<ANecro>(owner);
		if (_player)
		{
			_player->SetCanAttack(false);
		}
	}

}

void UAttackComponent::Init()
{
	owner = GetOwner();
}