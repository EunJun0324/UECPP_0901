#include "AnimInstances/C_AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "Components/C_CombatComponent.h"

void UC_AnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	OwningCharacter = Cast<ACharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		Movement = OwningCharacter->GetCharacterMovement();
		Combat = OwningCharacter->FindComponentByClass<UC_CombatComponent>();
	}
}

void UC_AnimInstance::NativeUpdateAnimation(float deltaSeconds)
{
	Super::NativeUpdateAnimation(deltaSeconds);

	if (!OwningCharacter || !Movement) return;

	{
		// Speed 설정
		FVector velocity = OwningCharacter->GetVelocity();
		velocity.Z = 0;
		Speed = velocity.Size();
	}

	{
		Direction = CalculateDirection(OwningCharacter->GetVelocity(), OwningCharacter->GetActorRotation());
	}

	{
		// bIsFalling 설정
		bIsFalling = Movement->IsFalling();
	}

	{
		if (Combat)
		{
			Type = Combat->GetWeaponType();
		}
	}
}
