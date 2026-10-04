#pragma once

#include "CoreMinimal.h"
#include "C_Type.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	WT_NONE    UMETA(DisplayName = "Unarmed"),
	WT_RIFLE   UMETA(DisplayName = "Rifle")  ,
	WT_SNIPER  UMETA(DisplayName = "Sniper") ,
	WT_SHOTGUN UMETA(DisplayName = "Shotgun"),
};

UENUM(BlueprintType)
enum class EItemType : uint8
{
	IT_WEAPON,
	IT_BULLET,
};
