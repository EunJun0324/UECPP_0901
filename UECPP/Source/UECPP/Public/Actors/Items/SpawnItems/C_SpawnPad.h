#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_SpawnPad.generated.h"

// AC_SpawnPad  : SpawnItem 을 주기적으로 생성하는 패드입니다.
// AC_SpawnItem : AC_SpawnPad 위에 생성되는 아이템입니다.

// SpawnPad 를 배치하여 AC_SpawnItem 을 생성시켜주시고
// AC_SpawnItem 에 플레이어가 충돌했다면 제거해주세요.
// 또한 SpawnPad 는 이미 아이템을 생성했다면 아이템을 생성하지 않습니다.
// 아이템이 제거 되어있다면 다시 생성을 하기 시작합니다.

UCLASS()
class UECPP_API AC_SpawnPad : public AActor
{
	GENERATED_BODY()

public:	
	AC_SpawnPad();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public :
	void StartSpawnTimer();

private :
	UFUNCTION()
	void SpawnTimerFunction();

private :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UNiagaraComponent> NiagaraComponent;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UNiagaraSystem> CreatingParticle;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UNiagaraSystem> CreatedParticle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AC_SpawnItem> SpawnItemClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float ZOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float SpawnTime = 10.f;

private :
	struct FTimerHandle SpawnTimer;
};
