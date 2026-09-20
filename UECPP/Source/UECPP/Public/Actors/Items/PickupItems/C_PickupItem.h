#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Types/C_Type.h"
#include "C_PickupItem.generated.h"

// 언리얼 추상 클래스 선언방법 : UCLASS(Abstract)
UCLASS(Abstract) // 블루프린트 , 코드에서 직접 인스턴스화를 막습니다.
class UECPP_API AC_PickupItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AC_PickupItem();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public :
	UFUNCTION()
	void OnCollsionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnCollsionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USphereComponent> Collision;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UWidgetComponent> WidgetComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Type", meta = (AllowPrivateAccess = "true"))
	EItemType ItemType;

public :
	FORCEINLINE EItemType GetItemType() const { return ItemType; }

};
