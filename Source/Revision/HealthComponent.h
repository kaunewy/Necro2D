// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class REVISION_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);
	UPROPERTY(BlueprintAssignable)
	FOnDeath onDeath;
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHit);
	UPROPERTY(BlueprintAssignable)
	FOnHit onHit;

protected:
	UPROPERTY(EditAnywhere)
	float life = 5.0f;
	
public:
	FOnDeath& OnDeath()
	{
		return onDeath;
	}
	FOnHit& GetOnHit()
	{
		return onHit;
	}

public:	
	UHealthComponent();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void TakeDamage(float _damageTake);

		
};
