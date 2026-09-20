

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Types/C_Type.h"
#include "C_AnimInstance.generated.h"


UCLASS()
class UECPP_API UC_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

private :
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float deltaSeconds) override;

protected :
	UPROPERTY(BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class ACharacter> OwningCharacter;

	UPROPERTY(BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCharacterMovementComponent> Movement;

protected :
	UPROPERTY(BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float Speed;

	UPROPERTY(BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float Direction;


	UPROPERTY(BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	bool bIsFalling;

	UPROPERTY(BlueprintReadOnly, Category = "Type", meta = (AllowPrivateAccess = "true"))
	EWeaponType Type;

private :
	class UC_CombatComponent* Combat;
};
