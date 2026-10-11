#include "Actors/Controllers/C_AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "GameFramework/Pawn.h"


AC_AIController::AC_AIController()
{
	//PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception")));

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius                  = SightRadius;
	SightConfig->LoseSightRadius              = LoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = PeripheralVisionAngleDegrees;
	SightConfig->SetMaxAge(MaxAge);

	SightConfig->DetectionByAffiliation.bDetectEnemies    = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals   = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

	PerceptionComponent->ConfigureSense(*SightConfig);
	PerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());
}

void AC_AIController::BeginPlay()
{
	Super::BeginPlay();
}

void AC_AIController::OnPossess(APawn* inPawn)
{
	Super::OnPossess(inPawn);

	PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ThisClass::OnTargetPerceptionUpdated);

	if (BehaivorTreeAsset)
	{
		RunBehaviorTree(BehaivorTreeAsset);

		UBlackboardComponent* bb = GetBlackboardComponent();

		if (bb == nullptr) return;

		bb->SetValueAsVector(TEXT("StartLocation"), inPawn->GetActorLocation());
	}
}

void AC_AIController::Tick(float deltaSeconds)
{
	UBlackboardComponent* bb = GetBlackboardComponent();

	if (bb != nullptr)
	{
		AActor* actor = Cast<AActor>(bb->GetValueAsObject(TargetKeyName));

		if (actor != nullptr)
		{
			float distance = FVector::DistXY(GetPawn()->GetActorLocation(), actor->GetActorLocation());

			bb->SetValueAsBool(TEXT("IsInRange"), distance < FireRange);
		}
	}
}

void AC_AIController::OnTargetPerceptionUpdated(AActor* actor, FAIStimulus stimuls)
{
	APawn* pawn = Cast<APawn>(actor);

	if (pawn == nullptr || !pawn->IsPlayerControlled()) return;

	UBlackboardComponent* bb = GetBlackboardComponent();

	if (bb == nullptr) return;

	if (stimuls.WasSuccessfullySensed())
	{
		bb->SetValueAsObject(TargetKeyName, actor);
		SetFocus(actor);
	}
	else
	{
		bb->ClearValue(TargetKeyName);
		ClearFocus(EAIFocusPriority::Gameplay);
	}
}
