// Copyright - Astrid Avalin Soerensen

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
	void AimAt(FVector HitLocation, float LaunchSpeed);
	void MoveBarrelTowards(FVector AimDirection);

private:	
	UStaticMeshComponent* Barrel = nullptr;
};
