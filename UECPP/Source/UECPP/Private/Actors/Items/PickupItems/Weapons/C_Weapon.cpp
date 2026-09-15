#include "Actors/Items/PickupItems/Weapons/C_Weapon.h"
#include "Components/SkeletalMeshComponent.h"

AC_Weapon::AC_Weapon()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

void AC_Weapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void AC_Weapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AC_Weapon::ApplyEffect(AC_Player* Picker)
{

}

