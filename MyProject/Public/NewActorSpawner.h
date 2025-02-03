#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NewActorSpawner.generated.h"

UCLASS()
class MYPROJECT_API ANewActorSpawner : public AActor
{
	GENERATED_BODY()

public:
	ANewActorSpawner();

	UFUNCTION()
	void SpawnActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|Components")
	class UBoxComponent* SpawnVolume;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|Position")
	float ActorRoatation;

	FTimerHandle MyTimerHandle;

	virtual void BeginPlay() override;
};