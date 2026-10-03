

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_Projectile.generated.h"

UCLASS()
class UECPP_API AC_Projectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AC_Projectile();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

protected :
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class USphereComponent> Collision;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UStaticMeshComponent> Mesh;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UParticleSystem> ImpactParticle;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class USoundCue> ImpactSound;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UMaterialInstanceConstant> HitDecal;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UProjectileMovementComponent> ProjectileMovement;
	
	UPROPERTY(EditDefaultsOnly)
	float DecalSize;
	
	UPROPERTY(EditDefaultsOnly)
	float Damage;
};
