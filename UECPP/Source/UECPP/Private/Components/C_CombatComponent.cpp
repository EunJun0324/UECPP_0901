#include "Components/C_CombatComponent.h"
#include "Actors/Items/PickupItems/Weapons/C_Weapon.h"

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
	return false;
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

