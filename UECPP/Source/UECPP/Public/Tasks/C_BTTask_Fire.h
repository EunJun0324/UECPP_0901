

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "C_BTTask_Fire.generated.h"

UCLASS()
class UECPP_API UC_BTTask_Fire : public UBTTaskNode
{
	GENERATED_BODY()
	
public :
	UC_BTTask_Fire();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected :
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector TargetKey;
};
