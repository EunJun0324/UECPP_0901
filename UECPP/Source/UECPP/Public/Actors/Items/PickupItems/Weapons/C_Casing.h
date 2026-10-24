

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_Casing.generated.h"

UCLASS()
class UECPP_API AC_Casing : public AActor
{
	GENERATED_BODY()
	
public:	
	AC_Casing();

protected:
	virtual void BeginPlay() override;

private :
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UStaticMeshComponent> CasingMesh;
};
