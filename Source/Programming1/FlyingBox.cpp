// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyingBox.h"
#include "Components/BoxComponent.h"

// Sets default values
AFlyingBox::AFlyingBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FlyingBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	FlyingBox->SetupAttachment(RootComponent);

	//getting cube static mesh from start content
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	//if cube mesh is succesfully loaded in
	if (CubeVisualAsset.Succeeded())
	{
		FlyingBox->SetStaticMesh(CubeVisualAsset.Object);
		FlyingBox->SetRelativeLocation(FVector(0.0f, 0.0f, 200.0f));
	}
	
	
}

// Called when the game starts or when spawned
void AFlyingBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlyingBox::Tick(float DeltaTime)
{
	//movement

	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * FloatSpeed;          
	float DeltaRotation = DeltaTime * RotationSpeed;   
	NewRotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewLocation, NewRotation);
}

