

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Types/C_Type.h"
#include "C_CombatComponent.generated.h"

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

public :
	bool PickupItem(class AC_PickupItem * item);

private :
	class AC_Weapon* EquippedWeapon;

public :
	EWeaponType GetWeaponType() const;
};
