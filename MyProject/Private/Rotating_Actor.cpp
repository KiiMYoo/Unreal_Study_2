#include "Rotating_Actor.h"
/* 회전 액터: 지속적으로 회전하는 액터
* 헬리콥터 프로펠러를 표현하기 위해 사용.
*/
ARotating_Actor::ARotating_Actor()
{
 	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticComp"));
	StaticComp->SetupAttachment(SceneRoot);

	RotationSpeed = 90.0f;
}

void ARotating_Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARotating_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

