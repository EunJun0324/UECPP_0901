

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

protected :
	virtual void ApplyEffect(class AC_Player* Picker) override;

protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USkeletalMeshComponent> Mesh;
};
