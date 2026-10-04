

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "C_CharacterOverlayWidget.generated.h"

/**
 * 
 */
UCLASS()
class UECPP_API UC_CharacterOverlayWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected :
	virtual void NativeConstruct() override;

public:
	void SetTextAMMO(int32 ammo, int32 totalAmmo);
	void SetTextWeaponType(FText weaponType);
	void SetTextAutomatic(bool bAutomaitc);
	void SetProgressBarHealth(float health, float maxHealth);
	void ShowCrosshair(bool bShow);

private :
	UPROPERTY(meta =(BindWidget))
	TObjectPtr<class UTextBlock> Text_WeaponType;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> Text_AMMO;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> Text_Automatic;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UProgressBar> ProgressBar_Health;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UImage> Image_Crosshair;

private :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FSlateColor ActivateAutomaitcColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FSlateColor DeactivateAutomaitcColor;
};
