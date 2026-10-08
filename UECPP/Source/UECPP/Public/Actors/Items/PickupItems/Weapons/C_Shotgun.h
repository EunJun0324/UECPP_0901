#pragma once

#include "CoreMinimal.h"
#include "Actors/Items/PickupItems/Weapons/C_Weapon.h"
#include "C_Shotgun.generated.h"

UCLASS()
class UECPP_API AC_Shotgun : public AC_Weapon
{
	GENERATED_BODY()
	
public :
	virtual void Fire(const FVector& hitTaghet) override;

private :
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ShotgunData", meta = (AllowPrivateAccess = "true"))
	float SpreadAngle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ShotgunData", meta = (AllowPrivateAccess = "true"))
	int32 SpreadCount;
};
