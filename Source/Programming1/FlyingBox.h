// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "FlyingBox.generated.h"


UCLASS()
class PROGRAMMING1_API AFlyingBox : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFlyingBox();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* FlyingBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
		float FloatSpeed = FMath::RandRange(70.0f,120.0f);

	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
		float RotationSpeed = 5.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};