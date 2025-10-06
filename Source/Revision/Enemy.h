// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "AttackComponent.h"
#include "Components/BoxComponent.h"
#include "HealthComponent.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class REVISION_API AEnemy : public APaperZDCharacter
{
	GENERATED_BODY()
	UPROPERTY()
	TObjectPtr<UAttackComponent> attackCompo = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> triggerBox = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UHealthComponent> healthCompo = nullptr;

public:
	AEnemy();

protected:
	virtual void BeginPlay() override;
	void Init();
	void BeginOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

};
