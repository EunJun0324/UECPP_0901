

#pragma once

#include "CoreMinimal.h"
#include "Actors/Items/PickupItems/C_PickupItem.h"

#include "C_Weapon.generated.h"




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

protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USkeletalMeshComponent> Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Type", meta = (AllowPrivateAccess = "true"))
	EWeaponType WeaponTpye;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Socket", meta = (AllowPrivateAccess = "true"))
	FName SocketName;

private :
	ACharacter* OwnerCharacter;

public :
	FORCEINLINE EWeaponType GetWeaponType() const { return WeaponTpye; }
};
