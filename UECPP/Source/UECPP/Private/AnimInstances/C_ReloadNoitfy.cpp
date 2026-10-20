#include "AnimInstances/C_ReloadNoitfy.h"
#include "Actors/Characters/C_Player.h"
#include "Components/C_CombatComponent.h"

FString UC_ReloadNoitfy::GetNotifyName_Implementation() const
{
	return "Reload";
}

void UC_ReloadNoitfy::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	AC_Player* player = Cast<AC_Player>(MeshComp->GetOwner());
	
	if (player == nullptr) return;

	player->GetCombatComponent()->ReloadUpateHUD();

	/*
	- MeshComp : 해당 노티파이가 발동된 스켈레탈 컴포넌트
	- Animation : 해당 노티파이가 들어있는 애니메이션 에셋
	- FAnimNotifyEventReference : 노티파이 발동 상세 정보
	*/

}
