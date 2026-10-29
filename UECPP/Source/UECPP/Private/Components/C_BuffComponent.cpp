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

	
}


void UC_BuffComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UC_BuffComponent::Buff(EBuffType buffType, float value)
{
	switch (buffType)
	{
	case EBuffType::BT_HEALING: HealingBuff(value);
		return;
	case EBuffType::BT_SPEED  : SpeedBuff(value);
		return;				  
	case EBuffType::BT_JUMP   : JumpBuff(value);
		return;
	default:
		return;
	}
}

void UC_BuffComponent::HealingBuff(float value)
{}

void UC_BuffComponent::SpeedBuff(float value)
{}

void UC_BuffComponent::JumpBuff(float value)
{}

