

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "C_ReloadNoitfy.generated.h"


UCLASS()
class UECPP_API UC_ReloadNoitfy : public UAnimNotify
{
	GENERATED_BODY()
public :

	/*
	UFUNCTION 지정자
	
	BlueprintCallable
	- Blueprint 호출이 가능
	- C++ 구현 존재
	- Blueprint Overriding 이 불가능
	
	BlueprintNativeEvent
	-Blueprint 호출이 가능
	- C++ 구현 존재
	- C++ 구현 규칙 존재 (함수명 뒤에 _Implementation 작성하여야함)
	- Blueprint Overriding 이 가능
	
	BlueprintImplementableEvent 
	- Blueprint 호출이 가능
	- C++ 구현 존재 x / 선언만 존재
	- Blueprint Overriding 이 가능
	*/
	FString GetNotifyName_Implementation() const override;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
