#include "Game/C_HUD.h"
#include "Widgets/C_CharacterOverlayWidget.h"

void AC_HUD::BeginPlay()
{
	Super::BeginPlay();

	AddCharacterOverlay();
}

void AC_HUD::AddCharacterOverlay()
{
	APlayerController* controller = GetOwningPlayerController();

	if (controller == nullptr || CharacterOverlayClass == nullptr) return;

	CharacterOverlay = CreateWidget<UC_CharacterOverlayWidget>(controller, CharacterOverlayClass);
	CharacterOverlay->AddToViewport();
}
