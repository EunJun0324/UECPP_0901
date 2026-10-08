#include "Actors/Items/PickupItems/C_Bullet.h"
#include "Kismet/KismetMathLibrary.h"

AC_Bullet::AC_Bullet()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	ItemType = EItemType::IT_BULLET;
}

void AC_Bullet::BeginPlay()
{
	Super::BeginPlay();

	// 랜덤값이 이상함.
	AMMO = UKismetMathLibrary::RandomIntegerInRange(RandomCountMin, RandomCountMax);
}
