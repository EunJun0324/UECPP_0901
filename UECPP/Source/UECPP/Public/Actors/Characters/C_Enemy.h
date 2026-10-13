

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "C_Enemy.generated.h"

UCLASS()
class UECPP_API AC_Enemy : public ACharacter
{
	GENERATED_BODY()

	// WidgetComponent
	// EnemyWidget
	// TakeDamage 를 이용해서 Hp 가 줄어들도록 만들어주시고, Hp 가 0 이 된다면 해당 액터를 삭제해주세요. 

public:
	AC_Enemy();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Fire(AActor* target);

private :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AC_Projectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USceneComponent> FirePoint;
};
