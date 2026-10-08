

#pragma once

#include "CoreMinimal.h"
#include "Actors/Items/PickupItems/Weapons/C_Weapon.h"
#include "C_Rifle.generated.h"

UCLASS()
class UECPP_API AC_Rifle : public AC_Weapon
{
	GENERATED_BODY()
	
public :
	virtual void Fire(const FVector& hitTaghet) override;
};
