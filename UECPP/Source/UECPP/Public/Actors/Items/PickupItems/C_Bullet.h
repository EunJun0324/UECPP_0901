

#pragma once

#include "CoreMinimal.h"
#include "Actors/Items/PickupItems/C_PickupItem.h"
#include "Types/C_Type.h"
#include "C_Bullet.generated.h"

UCLASS()
class UECPP_API AC_Bullet : public AC_PickupItem
{
	GENERATED_BODY()
	
public :
	AC_Bullet();

public :
	virtual void BeginPlay() override;

private :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BulletData", meta = (AllowPrivateAccess = "true"))
	EWeaponType BulletType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BulletData", meta = (AllowPrivateAccess = "true"))
	int32 RandomCountMax;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BulletData", meta = (AllowPrivateAccess = "true"))
	int32 RandomCountMin;

	int32 AMMO;

public:
	FORCEINLINE const int32& GetAMMO() { return AMMO; }
	FORCEINLINE const EWeaponType& GetBulletType() { return BulletType; }

};
