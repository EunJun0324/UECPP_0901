#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "C_EnemyWidget.generated.h"

UCLASS()
class UECPP_API UC_EnemyWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UProgressBar> ProgressBar_Health;

public:
	void UpdateHealth(float maxHp, float Hp);
};
