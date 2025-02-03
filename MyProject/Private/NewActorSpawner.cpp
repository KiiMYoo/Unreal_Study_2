#include "NewActorSpawner.h"
#include "Components/BoxComponent.h"
#include "ActorToSpawn.h"

ANewActorSpawner::ANewActorSpawner()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));

	SpawnVolume->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ActorRoatation = 0.0f;
}

void ANewActorSpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(
		MyTimerHandle,
		this,
		&ANewActorSpawner::SpawnActor,
		1.5f,
		true,
		20.0f
	);
}

void ANewActorSpawner::SpawnActor()
{
	FVector SpawnLocation = GetActorLocation();
	FRotator SpawnRotation = GetActorRotation();

	for (int i = 0; i < 8; i++)
	{
		GetWorld()->SpawnActor<AActorToSpawn>(FVector(SpawnLocation.X * FMath::FRandRange(1.0f, 1.9f), SpawnLocation.Y, SpawnLocation.Z), FRotator(0.0f, ActorRoatation, 0.0f));
	}
}