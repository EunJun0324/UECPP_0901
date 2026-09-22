

#pragma once

#include "CoreMinimal.h"
#include "Actors/Items/PickupItems/C_PickupItem.h"
#include "C_Weapon.generated.h"

USTRUCT(BlueprintType)
struct FWeaponAimData
{
	GENERATED_BODY()

public :
	UPROPERTY(EditDefaultsOnly)
	float TargetArmLength;

	UPROPERTY(EditDefaultsOnly)
	FVector SocketOffset;

	UPROPERTY(EditDefaultsOnly)
	bool bCameraLag;

	UPROPERTY(EditDefaultsOnly)
	float FieldofView;
};


UCLASS()
class UECPP_API AC_Weapon : public AC_PickupItem
{
	GENERATED_BODY()

public:	
	AC_Weapon();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public :
	virtual void Equip(class ACharacter* character);
	virtual void UnEquip();
	virtual void Aiming(bool bAiming);

protected :
	UFUNCTION()
	virtual void OnAiming(float output);
	
	virtual void SetAimData(FWeaponAimData aimData);

protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USkeletalMeshComponent> Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Type", meta = (AllowPrivateAccess = "true"))
	EWeaponType WeaponTpye;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Socket", meta = (AllowPrivateAccess = "true"))
	FName SocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "WeaponData", meta = (AllowPrivateAccess = "true"))
	FWeaponAimData AimData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "WeaponData", meta = (AllowPrivateAccess = "true"))
	FWeaponAimData BaseData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "WeaponData", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UTimelineComponent> Timeline;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "WeaponData", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCurveFloat> AimCurve;

private :
	ACharacter* OwnerCharacter;

public :
	FORCEINLINE EWeaponType GetWeaponType() const { return WeaponTpye; }
};
