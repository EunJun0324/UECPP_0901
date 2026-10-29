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
	void Buff(EBuffType buffType, float value);

private :
	void HealingBuff(float value);
	void SpeedBuff(float value);
	void JumpBuff(float value);
};
