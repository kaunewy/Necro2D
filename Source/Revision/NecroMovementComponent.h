// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InputActionValue.h"
#include "NecroMovementComponent.generated.h"


class ANecro;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class REVISION_API UNecroMovementComponent : public UActorComponent
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMovement, float, _move);
	UPROPERTY(BlueprintAssignable)
	FOnMovement onMovement;

public:
	TObjectPtr<ANecro> owner = nullptr;


public:
	FOnMovement& OnMovement()
	{
		return onMovement;
	};

public:	
	UNecroMovementComponent();
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public:
	UFUNCTION() void Move(const FInputActionValue& _value);
		
};
