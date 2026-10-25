

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;


	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UNiagaraSystem> Particle;
};
