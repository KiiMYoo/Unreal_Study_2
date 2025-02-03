#include "MovingFloor.h"

/* �պ� �̵� ����: ���������� ���� �Ÿ���ŭ �պ� �̵��ϴ� ����.
* ��鸮�� �� ������ �÷��� ǥ���ϱ� ���� ���.
*/
AMovingFloor::AMovingFloor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticComp"));
	StaticComp->SetupAttachment(SceneRoot);

	MoveSpeedX = 0.0f;
	MoveSpeedY = 0.0f;
	MoveSpeedZ = 0.0f;
	MaxDistance = 0.0f;
	bMovingUp = true;
	StartLocation = FVector(0.0f, 0.0f, 0.0f);
}

void AMovingFloor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
			
}

void AMovingFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	if (DistanceMoved >= MaxDistance)
	{
		bMovingUp = !bMovingUp;
	}
	
	float Direction = bMovingUp ? 1.0f : -1.0f;

	if (!FMath::IsNearlyZero(MoveSpeedZ))
	{
		AddActorLocalOffset(FVector(0.0f, 0.0f, MoveSpeedZ * Direction * DeltaTime));
	}
	if(!FMath::IsNearlyZero(MoveSpeedX))
	{
		AddActorLocalOffset(FVector(MoveSpeedX * Direction * DeltaTime, 0.0f, 0.0f));
	}
	if (!FMath::IsNearlyZero(MoveSpeedY))
	{
		AddActorLocalOffset(FVector(0.0f, MoveSpeedY * Direction * DeltaTime, 0.0f));
	}
}
