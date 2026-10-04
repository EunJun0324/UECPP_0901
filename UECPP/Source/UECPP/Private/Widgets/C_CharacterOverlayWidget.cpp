#include "Widgets/C_CharacterOverlayWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Components/Image.h"

void UC_CharacterOverlayWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetTextAutomatic(false);
	ShowCrosshair(false);
}

void UC_CharacterOverlayWidget::SetTextAMMO(int32 ammo, int32 totalAmmo)
{
	const FString str = FString::Printf(TEXT("%d / %d"), ammo, totalAmmo);
	Text_AMMO->SetText(FText::FromString(str));
}

void UC_CharacterOverlayWidget::SetTextWeaponType(FText weaponType)
{
	Text_WeaponType->SetText(weaponType);
}

void UC_CharacterOverlayWidget::SetTextAutomatic(bool bAutomaitc)
{
	if (bAutomaitc) { Text_Automatic->SetColorAndOpacity(ActivateAutomaitcColor);   }
	else            { Text_Automatic->SetColorAndOpacity(DeactivateAutomaitcColor); }
}

void UC_CharacterOverlayWidget::SetProgressBarHealth(float health, float maxHealth)
{
	ProgressBar_Health->SetPercent(health / maxHealth);
}

void UC_CharacterOverlayWidget::ShowCrosshair(bool bShow)
{
	if (bShow) { Image_Crosshair->SetVisibility(ESlateVisibility::Visible); }
	else       { Image_Crosshair->SetVisibility(ESlateVisibility::Hidden);  }
}
