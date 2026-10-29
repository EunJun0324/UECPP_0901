#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Types/C_Type.h"
#include "C_BuffComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UECPP_API UC_BuffComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UC_BuffComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public :
	void Buff(FBuff buff);
	void DeactiveBuff(FBuff buff);

private :
	void HealingBuff(FBuff buff);
	void SpeedBuff(FBuff buff, bool activated);
	void JumpBuff(FBuff buff, bool activated);

private :
	TArray<FBuff> ActiveBuffs;
	class AC_Player* Player;

private :
	float BaseSpeed;
	float BaseJumpForce;
};
