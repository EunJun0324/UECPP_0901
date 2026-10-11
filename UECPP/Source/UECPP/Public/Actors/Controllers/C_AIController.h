#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "C_AIController.generated.h"


UCLASS()
class UECPP_API AC_AIController : public AAIController
{
	GENERATED_BODY()

public:
	AC_AIController();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* inPawn);
	virtual void Tick(float deltaSeconds);
	
	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* actor, struct FAIStimulus stimuls);

private :
	UPROPERTY()
	TObjectPtr<class UAISenseConfig_Sight> SightConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="AI", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UBehaviorTree> BehaivorTreeAsset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
	FName TargetKeyName = TEXT("TargetActor");

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
	float FireRange = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Sight", meta = (AllowPrivateAccess = "true"))
	float SightRadius = 1500.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sight", meta = (AllowPrivateAccess = "true"))
	float LoseSightRadius = 1800.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sight", meta = (AllowPrivateAccess = "true"))
	float PeripheralVisionAngleDegrees = 60.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sight", meta = (AllowPrivateAccess = "true"))
	float MaxAge = 3.f;


};
