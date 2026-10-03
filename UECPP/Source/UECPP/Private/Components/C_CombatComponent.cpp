#include "Components/C_CombatComponent.h"
#include "Actors/Items/PickupItems/Weapons/C_Weapon.h"
#include "Actors/Characters/C_Player.h"
#include "Kismet/GameplayStatics.h"

UC_CombatComponent::UC_CombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UC_CombatComponent::BeginPlay()
{
	Super::BeginPlay();

	bAutomatic = true;
}


void UC_CombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

bool UC_CombatComponent::EquipWeapon(AC_Weapon* weapon)
{
	if (EquippedWeapon)
	{
		EquippedWeapon->UnEquip();
		EquippedWeapon = nullptr;
	}

	weapon->Equip(Cast<AC_Player>(GetOwner()));

	EquippedWeapon = weapon;

	return true;
}

bool UC_CombatComponent::AddBullet(AC_PickupItem* item)
{
	return false;
}

void UC_CombatComponent::TraceUnderCrosshair(FHitResult& result)
{
	FVector2D viewportSize;

	if (GEngine != nullptr && GEngine->GameViewport != nullptr)
	{
		GEngine->GameViewport->GetViewportSize(viewportSize);
	}

	FVector2D crosshairLocation = FVector2D(viewportSize.X / 2.f, viewportSize.Y / 2.f);

	FVector crosshairWorldLocation;
	FVector crosshairDirection;


	bool bScreenToWorld = UGameplayStatics::DeprojectScreenToWorld(
		UGameplayStatics::GetPlayerController(this, 0),
		crosshairLocation,
		crosshairWorldLocation,
		crosshairDirection
	);

	if (bScreenToWorld)
	{
		FVector start = crosshairWorldLocation + crosshairDirection;

		float distanceToCharacter = (GetOwner()->GetActorLocation() - start).Size();
		start += crosshairDirection * distanceToCharacter;

		FVector end = start + crosshairDirection* HitDistance;

		FCollisionQueryParams params;
		params.AddIgnoredActor(GetOwner());
		params.AddIgnoredActor(EquippedWeapon);

		GetWorld()->LineTraceSingleByChannel
		(
			result,
			start,
			end,
			ECC_Shot,
			params
		);

		if (!result.bBlockingHit)
		{
			result.ImpactPoint = end;
		}
	}
}

void UC_CombatComponent::OnFiring()
{
	if (!bFiring || EquippedWeapon == nullptr || !bAutomatic) return;

	FHitResult hitReuslt;
	TraceUnderCrosshair(hitReuslt);
	EquippedWeapon->Fire(hitReuslt.ImpactPoint);
}

bool UC_CombatComponent::PickupItem(AC_PickupItem* item)
{
	switch (item->GetItemType())
	{
	case EItemType::IT_WEAPON: return EquipWeapon(Cast<AC_Weapon>(item));
	case EItemType::IT_BULLET: return AddBullet(item);
	}
	return false;
}

void UC_CombatComponent::SetAiming(bool bIsAiming)
{
	if (EquippedWeapon == nullptr) return;

	bAiming = bIsAiming;

	EquippedWeapon->Aiming(bIsAiming);
}

void UC_CombatComponent::Firing(bool bIsFiring)
{
	if (EquippedWeapon == nullptr) return;

	bFiring = bIsFiring;
	
	if (bFiring)
	{
		FHitResult hitReuslt;
		TraceUnderCrosshair(hitReuslt);
		EquippedWeapon->Fire(hitReuslt.ImpactPoint);
		FTimerManagerTimerParameters param;
		param.bLoop = true;
		GetOwner()->GetWorldTimerManager().SetTimer
		(
			FireTimer,
			this,
			&ThisClass::OnFiring,
			0.15f,
			param
		);
	}
	else
	{
		GetOwner()->GetWorldTimerManager().ClearTimer(FireTimer);
	}
}

EWeaponType UC_CombatComponent::GetWeaponType() const
{
	if (EquippedWeapon)
	{ return EquippedWeapon->GetWeaponType(); }
	else
	{ return EWeaponType::WT_NONE; }
}

