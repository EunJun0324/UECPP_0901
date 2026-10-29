#include "Components/C_BuffComponent.h"
#include "Actors/Characters/C_Player.h"
#include "GameFramework/CharacterMovementComponent.h"

UC_BuffComponent::UC_BuffComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UC_BuffComponent::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<AC_Player>(GetOwner());

	BaseSpeed = Player->GetCharacterMovement()->GetMaxSpeed();
	BaseJumpForce = Player->GetCharacterMovement()->JumpZVelocity;
}


void UC_BuffComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	for (int32 i = 0; i < ActiveBuffs.Num(); i++)
	{
		FBuff& buff = ActiveBuffs[i];
		if (buff.Type == EBuffType::BT_HEALING)
		{
			// 힐링
		}
	
		buff.Remaining += DeltaTime;
	
		if (buff.Remaining >= buff.Duration)
		{
			DeactiveBuff(buff);
			ActiveBuffs.RemoveAtSwap(i);
		}
	}

}

void UC_BuffComponent::Buff(FBuff buff)
{
	ActiveBuffs.Add(buff);

	switch (buff.Type)
	{
	case EBuffType::BT_HEALING : return;
	case EBuffType::BT_JUMP    : JumpBuff(buff, true);
	case EBuffType::BT_SPEED   : SpeedBuff(buff, true);
	default:
		return;
	}
}

void UC_BuffComponent::DeactiveBuff(FBuff buff)
{


	switch (buff.Type)
	{
	case EBuffType::BT_HEALING: return;
	case EBuffType::BT_JUMP   : JumpBuff(buff, false);
	case EBuffType::BT_SPEED  : SpeedBuff(buff, false);
	default:
		return;
	}
}

void UC_BuffComponent::HealingBuff(FBuff buff)
{}

void UC_BuffComponent::SpeedBuff(FBuff buff, bool activated)
{
	if (activated)
	{
		Player->GetCharacterMovement()->MaxWalkSpeed = BaseJumpForce + buff.Value;
	}
	else
	{
		Player->GetCharacterMovement()->MaxWalkSpeed = BaseJumpForce;
	}
}

void UC_BuffComponent::JumpBuff(FBuff buff, bool activated)
{
	if (activated)
	{
		Player->GetCharacterMovement()->JumpZVelocity = BaseJumpForce + buff.Value;
	}
	else
	{
		Player->GetCharacterMovement()->JumpZVelocity = BaseJumpForce;
	}
}


