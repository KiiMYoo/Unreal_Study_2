
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OneWayMovingActor.generated.h"

UCLASS()
class MYPROJECT_API AOneWayMovingActor : public AActor
{
	GENERATED_BODY()
	
public:
	AOneWayMovingActor();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|Components")
	UStaticMeshComponent* StaticComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|ActorMove")
	float MoveSpeedZ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|ActorMove")
	float MaxDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|ActorMove")
	float StartTime;

	FVector StartLocation;
	FTimerHandle MyTimerhandle;
	
	UFUNCTION(BlueprintCallable)
	void StartTimer();
	UFUNCTION()
	void MoveActor();
	UFUNCTION()
	void EndTimer();
};	
