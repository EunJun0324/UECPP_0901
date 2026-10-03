

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "C_HUD.generated.h"

/**
 * 
 */
UCLASS()
class UECPP_API AC_HUD : public AHUD
{
	GENERATED_BODY()
	
public :
	virtual void BeginPlay() override;

public : 
	void AddCharacterOverlay();

protected :
	UPROPERTY()
	TObjectPtr<class UC_CharacterOverlayWidget> CharacterOverlay;

	UPROPERTY(EditAnywhere, Category = "CharacterOverlay", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UUserWidget> CharacterOverlayClass;
};
