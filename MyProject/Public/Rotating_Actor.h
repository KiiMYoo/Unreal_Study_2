#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rotating_Actor.generated.h"

UCLASS()
class MYPROJECT_API ARotating_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotating_Actor();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|Components")
	UStaticMeshComponent* StaticComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|ActorMove")
	float RotationSpeed;
};
