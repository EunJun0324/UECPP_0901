#include "Actors/Items/PickupItems/C_PickupItem.h"
#include "Components/SphereComponent.h"


AC_PickupItem::AC_PickupItem()
{
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	RootComponent = Collision;
}

void AC_PickupItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AC_PickupItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

