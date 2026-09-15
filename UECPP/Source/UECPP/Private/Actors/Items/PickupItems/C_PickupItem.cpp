#include "Actors/Items/PickupItems/C_PickupItem.h"
#include "Actors/Characters/C_Player.h"
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
	
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AC_PickupItem::OnCollsionBeginOverlap);
}

void AC_PickupItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AC_PickupItem::OnCollsionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AC_Player* player = Cast<AC_Player>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("BeginOverlap"));
	}
}

