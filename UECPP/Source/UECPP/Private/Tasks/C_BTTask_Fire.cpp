#include "Tasks/C_BTTask_Fire.h"
#include "Actors/Characters/C_Enemy.h"
#include "Actors/Controllers/C_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UC_BTTask_Fire::UC_BTTask_Fire()
{
	NodeName = "TaskFire";
}

EBTNodeResult::Type UC_BTTask_Fire::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* aiController = OwnerComp.GetAIOwner();
	
	UBlackboardComponent* bb = OwnerComp.GetBlackboardComponent();

	if (aiController == nullptr || bb == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AC_Enemy* enemy = Cast<AC_Enemy>(aiController->GetPawn());
	AActor* target = Cast<AActor>(bb->GetValueAsObject(TargetKey.SelectedKeyName));

	if (enemy == nullptr || target == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	enemy->Fire(target);
	return EBTNodeResult::Succeeded;
}
