#pragma once

#include "CoreMinimal.h"
#include "C_Type.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	WT_NONE,
	WT_RIFLE,
	WT_SNIPER,
	WT_SHOTGUN,
};

UENUM(BlueprintType)
enum class EItemType : uint8
{
	IT_WEAPON,
	IT_BULLET,
};
