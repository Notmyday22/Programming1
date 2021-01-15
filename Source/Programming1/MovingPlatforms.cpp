// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatforms.h"
#include "Components/BoxComponent.h"

// Sets default values
AMovingPlatforms::AMovingPlatforms()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FlyingBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	FlyingBox->SetupAttachment(RootComponent);

	//calling cubeshape from starter content
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	//if cube mesh is succesfully loaded in
	if (CubeVisualAsset.Succeeded())
	{
		FlyingBox->SetStaticMesh(CubeVisualAsset.Object);
		FlyingBox->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

}

// Called when the game starts or when spawned
void AMovingPlatforms::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingPlatforms::Tick(float DeltaTime)
{
	
	//movement
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Y += DeltaHeight * FloatSpeed;
	NewLocation.Z += DeltaHeight * FloatSpeed; //Scale our height by FloatSpeed
	float DeltaRotation = DeltaTime * RotationSpeed;    //Rotate by a number of degrees equal to RotationSpeed each second
	NewRotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewLocation, NewRotation);
}

