#include "MovingFloor.h"

/* 왕복 이동 액터: 지속적으로 일정 거리만큼 왕복 이동하는 액터.
* 흔들리는 땅 형태의 플랫폼 표현하기 위해 사용.
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
