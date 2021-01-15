#include "TubeLightSwitch.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
ATubeLightSwitch::ATubeLightSwitch()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	//Light Intensity can be changed in editor
	LightIntensity = 3000.0f;
	//Creating Point Light Component
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	PointLight->Intensity = LightIntensity;

	//Set visibility, original UE documentation used bVisible but it did not work, Setvisibility did
	PointLight->SetVisibility(true);

	RootComponent = PointLight;

	LightSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Light Sphere Component"));
	LightSphere->InitSphereRadius(300.0f);
	LightSphere->SetCollisionProfileName(TEXT("Trigger"));
	LightSphere->SetupAttachment(RootComponent);

	LightSphere->OnComponentBeginOverlap.AddDynamic(this, &ATubeLightSwitch::OnOverlapBegin);
	LightSphere->OnComponentEndOverlap.AddDynamic(this, &ATubeLightSwitch::OnOverlapEnd);

}

// Called when the game starts or when spawned
void ATubeLightSwitch::BeginPlay()
{
	Super::BeginPlay();

	

}

// Called every frame
void ATubeLightSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//OnOverLap light becomes visible
void ATubeLightSwitch::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}
//On overlap ends, light becomes inivisible
void ATubeLightSwitch::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

void ATubeLightSwitch::ToggleLight()
{
	PointLight->ToggleVisibility();
}