// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyMovementComponent.generated.h"


class AEnemy;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class REVISION_API UEnemyMovementComponent : public UActorComponent
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnForward, float, _value);
	UPROPERTY(BlueprintAssignable)
	FOnForward onForward;


protected:
	AEnemy* owner = nullptr;
	FVector direction = FVector(1.0f,0.0f,0.0f);
	float speed = 50.0f;
	bool isBound = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool canMove = true;



public:	
	UEnemyMovementComponent();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Init();
	void Move();
	/*UFUNCTION() void EnemyHitWall(UPrimitiveComponent* HitComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit);*/
		
};
