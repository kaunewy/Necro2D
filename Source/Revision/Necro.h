// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "InputMappingContext.h"
#include "NecroMovementComponent.h"
#include "AttackComponent.h"
#include "Components/BoxComponent.h"
#include "HealthComponent.h"
#include "Necro.generated.h"

UENUM()
enum class EInputTypes
{
	NONE,
	MOVE,
	JUMP,
	ATTACK
};

USTRUCT()
struct FInput
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext> _mappingContext = nullptr;
	UPROPERTY(EditAnywhere)
	TMap<EInputTypes, TObjectPtr<UInputAction>> _inputMap;

	FInput()
	{

	};
};

/**
 * 
 */
UCLASS()
class REVISION_API ANecro : public APaperZDCharacter
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	FInput _inputs = FInput();
	UPROPERTY()
	TObjectPtr<UNecroMovementComponent> movementCompo = nullptr;
	UPROPERTY()
	TObjectPtr<UAttackComponent> attackCompo = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> triggerBox = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UHealthComponent> healthCompo = nullptr;
	UPROPERTY(EditAnywhere)
	AActor* enemy = nullptr;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool canAttack = false;

public:
	UFUNCTION(BlueprintCallable)
	FORCEINLINE UNecroMovementComponent* GetMovementCompo() const
	{
		return movementCompo;
	};
	UFUNCTION(BlueprintCallable)
	FORCEINLINE UAttackComponent* GetAttackCompo() const
	{
		return attackCompo;
	};
	UFUNCTION(BlueprintCallable)
	FORCEINLINE UBoxComponent* GetTriggerBox() const
	{
		return triggerBox;
	}
	UFUNCTION(BlueprintCallable)
	FORCEINLINE UHealthComponent* GetHealthComponent() const
	{
		return healthCompo;
	}
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetCanAttack(const bool& _value)
	{
		canAttack = _value;
	}



public:
	ANecro();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float _deltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
    void Init();
	UFUNCTION() void OnBeginOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
	UFUNCTION() void OnEndOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);
};
