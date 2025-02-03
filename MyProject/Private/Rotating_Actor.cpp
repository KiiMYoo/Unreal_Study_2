#include "Rotating_Actor.h"
/* ȸ�� ����: ���������� ȸ���ϴ� ����
* �︮���� �����緯�� ǥ���ϱ� ���� ���.
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

