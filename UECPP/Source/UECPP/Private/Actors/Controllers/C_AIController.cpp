#include "Actors/Controllers/C_AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Kismet/KismetMathLibrary.h"
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

		StartLocation = inPawn->GetActorLocation();
		StartRotation = inPawn->GetActorRotation();
		IdleYaw = StartRotation.Yaw;
	}
}

void AC_AIController::Tick(float deltaSeconds)
{
	UBlackboardComponent* bb = GetBlackboardComponent();

	if (bb != nullptr)
	{
		AActor* actor = Cast<AActor>(bb->GetValueAsObject(TargetKeyName));
		FVector actorLoc = GetPawn()->GetActorLocation();

		const float distFromStart = FVector::Dist2D(actorLoc, StartLocation);

		if (actor != nullptr && distFromStart < LeashDinstance)
		{
			FVector targetLoc = actor->GetActorLocation();
			float distance = FVector::Dist2D(actorLoc, targetLoc);

			bb->SetValueAsBool(TEXT("IsInRange"), distance < FireRange);

			FRotator lookRot = UKismetMathLibrary::FindLookAtRotation(actorLoc, targetLoc);

			SmoothRotateToYaw(lookRot.Yaw, deltaSeconds);

		}
		else
		{
			if (distFromStart > 100)
			{
				EPathFollowingRequestResult::Type result  = MoveToLocation(StartLocation, 80);
				FRotator lookRot = UKismetMathLibrary::FindLookAtRotation(actorLoc, StartLocation);
				SmoothRotateToYaw(lookRot.Yaw, deltaSeconds);
			}
			else
			{
				TurnTimer += deltaSeconds;

				if (TurnTimer >= TurnInterval)
				{
					TurnTimer = 0;
					IdleYaw = FRotator::NormalizeAxis(IdleYaw + 90.f);
				}
				SmoothRotateToYaw(IdleYaw, deltaSeconds);
			}
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
	}
	else
	{
		bb->ClearValue(TargetKeyName);
		TurnTimer = 0;
	}
}

void AC_AIController::SmoothRotateToYaw(float tagetYaw, float deltaTime)
{
	FRotator newRot = FMath::RInterpTo(GetPawn()->GetActorRotation(), FRotator(0.f, tagetYaw, 0.f), deltaTime, RotationSpeed);

	GetPawn()->SetActorRotation(newRot);

	SetControlRotation(newRot);
}
