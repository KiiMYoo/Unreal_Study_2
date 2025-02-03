#include "RotatingActorTimer.h"
#include "TimerManager.h"

/* ���� ȸ�� ����: ���� ���� ȸ�� �� �����ϴ� ����.
* �������� �ǹ� ǥ���ϱ� ���� ���.
*/

ARotatingActorTimer::ARotatingActorTimer()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticComp"));
	StaticComp->SetupAttachment(RootComponent);
	StaticComp->SetSimulatePhysics(true);

	RoatatingSpeed = 0.0f;
	StartTime = 0.0f;
	AccumulatedPitch = 0.0f;
	MaxPitch = 0.0f;
	StartRotation = FRotator(0.0f, 0.0f, 0.0f);
	CurrentRotation = FRotator(0.0f, 0.0f, 0.0f);
}

void ARotatingActorTimer::BeginPlay()
{
	Super::BeginPlay();

	StartRotation = GetActorRotation();

	GetWorldTimerManager().SetTimer(
		RotateTimeHandle,
		this,
		&ARotatingActorTimer::RotateActor,
		0.03f,
		true,
		StartTime
	);

}

void ARotatingActorTimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentRotation = GetActorRotation();

	if (FMath::Abs(CurrentRotation.Pitch) >= MaxPitch)
	{
		EndTimer();
	}
}

void ARotatingActorTimer::EndTimer()
{
	GetWorldTimerManager().ClearTimer(RotateTimeHandle);
}

void ARotatingActorTimer::RotateActor()
{
	float DeltaTime = GetWorld()->GetDeltaSeconds();

	AddActorLocalRotation(FRotator(RoatatingSpeed * DeltaTime, 0.0f, 0.0f));
}

