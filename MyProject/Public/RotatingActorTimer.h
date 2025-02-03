
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActorTimer.generated.h"

UCLASS()
class MYPROJECT_API ARotatingActorTimer : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingActorTimer();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	FTimerHandle MyTimerHandle;
	FTimerHandle RotateTimeHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|Components")
	UStaticMeshComponent* StaticComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|ActorMove")
	float RoatatingSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|ActorMove")
	float EndTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|ActorMove")
	float StartTime;

	FRotator StartRotation;
	FRotator CurrentRotation;
	float AccumulatedPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|ActorMove")
	float MaxPitch;

	void EndTimer();
	void RotateActor();
};
