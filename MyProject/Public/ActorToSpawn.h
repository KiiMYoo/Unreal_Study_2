#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorToSpawn.generated.h"

UCLASS()
class MYPROJECT_API AActorToSpawn : public AActor
{
	GENERATED_BODY()

public:
	AActorToSpawn();
	virtual void BeginPlay() override;

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticComp;
	float MoveSpeedX;
	float MoveSpeedY;
	float MoveSpeedZ;
	float StartTime;
	float EndTime;

	FVector StartLocation;
	FTimerHandle MyTimerhandle;
	FTimerHandle EndTimerhandle;

	void MoveActor();
	void DestroyActor();
};