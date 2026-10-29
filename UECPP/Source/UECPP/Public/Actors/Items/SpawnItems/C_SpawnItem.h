

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Types/C_Type.h"
#include "C_SpawnItem.generated.h"

UCLASS()
class UECPP_API AC_SpawnItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AC_SpawnItem();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private :
	UFUNCTION()
	void OnCollsionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USphereComponent> Collision;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UStaticMeshComponent> Mesh;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UNiagaraSystem> Particle;

	UPROPERTY(EditDefaultsOnly)
	float RotateSpeed;

	UPROPERTY(EditDefaultsOnly)
	FBuff BuffInfo;
};
