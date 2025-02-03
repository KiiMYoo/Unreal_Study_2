#include "OneWayMovingActor.h"
#include "TimerManager.h"

/*�Ϲ��� �̵� ���� : z������ ���� �Ÿ� �̵� �� ����.
*�������� ���� ǥ���ϱ� ���� ���.
*/

AOneWayMovingActor::AOneWayMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticComp"));
	StaticComp->SetupAttachment(SceneRoot);

	MoveSpeedZ = 0.0f;
	MaxDistance = 0.0f;
	StartLocation = FVector(0.0f, 0.0f, 0.0f);
	StartTime = 0.0f;
}

void AOneWayMovingActor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AOneWayMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	
	if (FMath::Abs(CurrentLocation.Z - StartLocation.Z) >= MaxDistance)
	{
		EndTimer();
	}
}

void AOneWayMovingActor::StartTimer()
{
	GetWorldTimerManager().SetTimer(
		MyTimerhandle,
		this,
		&AOneWayMovingActor::MoveActor,
		0.03f,
		true,
		StartTime
	);
}

void AOneWayMovingActor::MoveActor()
{

	float DeltaTime = GetWorld()->GetDeltaSeconds();

	if (!FMath::IsNearlyZero(MoveSpeedZ))
	{
		AddActorLocalOffset(FVector(0.0f,0.0f,MoveSpeedZ * DeltaTime));
	}
}

void AOneWayMovingActor::EndTimer()
{
	GetWorldTimerManager().ClearTimer(MyTimerhandle);
}
