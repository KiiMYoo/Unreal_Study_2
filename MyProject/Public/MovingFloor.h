#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingFloor.generated.h"


UCLASS()
class MYPROJECT_API AMovingFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingFloor();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|Components")
	UStaticMeshComponent* StaticComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|ActorMove")
	float MoveSpeedX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|ActorMove")
	float MoveSpeedY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|ActorMove")
	float MoveSpeedZ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|ActorMove")
	float MaxDistance;

	FVector StartLocation;
	bool bMovingUp;
};
