#include "ActorToSpawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

/* 스폰용 액터: 액터 스포너에서 스폰시킬 액터.
* 랜덤 속도로 이동하는 자동차를 표현하기 위해 사용.
*/

AActorToSpawn::AActorToSpawn()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticComp"));
	StaticComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/VehicleVarietyVol2/Meshes/SM_Sedan_01a.SM_Sedan_01a"));
	if (MeshAsset.Succeeded())
	{
		StaticComp->SetStaticMesh(MeshAsset.Object);
	}

	MoveSpeedX = FMath::FRandRange(8000.0f, 10000.0f);
	MoveSpeedY = 0.0f;
	MoveSpeedZ = 0.0f;

	StartTime = 0.0f;
	EndTime = 10.0f;

}

void AActorToSpawn::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

	GetWorldTimerManager().SetTimer(
		MyTimerhandle,
		this,
		&AActorToSpawn::MoveActor,
		0.03f,
		true,
		StartTime
	);

	GetWorldTimerManager().SetTimer(
		EndTimerhandle,
		this,
		&AActorToSpawn::DestroyActor,
		StartTime + EndTime,
		false
	);
}

void AActorToSpawn::MoveActor()
{

	float DeltaTime = GetWorld()->GetDeltaSeconds();

	if (!FMath::IsNearlyZero(MoveSpeedZ))
	{
		AddActorLocalOffset(FVector(0.0f, 0.0f, MoveSpeedZ * DeltaTime));
	}
	if (!FMath::IsNearlyZero(MoveSpeedX))
	{
		AddActorLocalOffset(FVector(MoveSpeedX * DeltaTime, 0.0f, 0.0f));
	}
	if (!FMath::IsNearlyZero(MoveSpeedY))
	{
		AddActorLocalOffset(FVector(0.0f, MoveSpeedY * DeltaTime, 0.0f));
	}
}

void AActorToSpawn::DestroyActor()
{
	Destroy();
}
