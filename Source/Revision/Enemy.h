// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "AttackComponent.h"
#include "Components/BoxComponent.h"
#include "HealthComponent.h"
#include "EnemyMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "Components/CapsuleComponent.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class REVISION_API AEnemy : public AActor
{
	GENERATED_BODY()
	UPROPERTY()
	TObjectPtr<UAttackComponent> attackCompo = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> triggerBox = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UHealthComponent> healthCompo = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UEnemyMovementComponent> moveCompo = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UPaperFlipbookComponent> sprite = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCapsuleComponent> capsule = nullptr;


public:
	FORCEINLINE UCapsuleComponent* GetCapsuleComponent() const
	{
		return capsule;
	}
	FORCEINLINE UHealthComponent* GetHealthComponent() const
	{
		return healthCompo;
	}

public:
	AEnemy();

protected:
	virtual void BeginPlay() override;
	void Init();
	UFUNCTION() void BeginOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

};
