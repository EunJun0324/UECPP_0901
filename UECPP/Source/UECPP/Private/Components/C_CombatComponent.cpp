#include "Components/C_CombatComponent.h"
#include "Actors/Items/PickupItems/Weapons/C_Weapon.h"
#include "Actors/Characters/C_Player.h"

UC_CombatComponent::UC_CombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UC_CombatComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UC_CombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

bool UC_CombatComponent::EquipWeapon(AC_Weapon* weapon)
{
	if (EquippedWeapon)
	{
		EquippedWeapon->UnEquip();
		EquippedWeapon = nullptr;
	}

	weapon->Equip(Cast<AC_Player>(GetOwner()));

	EquippedWeapon = weapon;

	return true;
}

bool UC_CombatComponent::AddBullet(AC_PickupItem* item)
{
	return false;
}

bool UC_CombatComponent::PickupItem(AC_PickupItem* item)
{
	switch (item->GetItemType())
	{
	case EItemType::IT_WEAPON: return EquipWeapon(Cast<AC_Weapon>(item));
	case EItemType::IT_BULLET: return AddBullet(item);
	}
	return false;
}

EWeaponType UC_CombatComponent::GetWeaponType() const
{
	if (EquippedWeapon)
	{ return EquippedWeapon->GetWeaponType(); }
	else
	{ return EWeaponType::WT_NONE; }
}

