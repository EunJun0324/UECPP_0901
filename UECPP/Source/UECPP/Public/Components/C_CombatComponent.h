

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Types/C_Type.h"
#include "C_CombatComponent.generated.h"

#define ECC_Shot ECollisionChannel::ECC_GameTraceChannel11

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UECPP_API UC_CombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UC_CombatComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private :
	bool EquipWeapon(class AC_Weapon* weapon);
	bool AddBullet(class AC_PickupItem* item);
	void TraceUnderCrosshair(FHitResult& result);

	UFUNCTION()
	void OnFiring();

public :
	bool PickupItem(class AC_PickupItem * item);
	void SetAiming(bool bIsAiming);
	void Firing(bool bIsFiring);

protected :
	UPROPERTY(EditAnywhere, Category = "HitDistance", meta = (AllowPrivateAccess = "true"))
	float HitDistance;

private :
	class AC_Weapon* EquippedWeapon;
	struct FTimerHandle FireTimer;
	
	bool bAiming;
	bool bFiring;
	bool bAutomatic;

public :
	EWeaponType GetWeaponType() const;
};
