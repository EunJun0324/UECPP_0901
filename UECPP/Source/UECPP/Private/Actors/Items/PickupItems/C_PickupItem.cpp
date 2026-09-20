#include "Actors/Items/PickupItems/C_PickupItem.h"
#include "Actors/Characters/C_Player.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"


AC_PickupItem::AC_PickupItem()
{
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	RootComponent = Collision;
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetupAttachment(RootComponent);
	WidgetComponent->SetVisibility(false);
}

void AC_PickupItem::BeginPlay()
{
	Super::BeginPlay();
	
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AC_PickupItem::OnCollsionBeginOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &AC_PickupItem::OnCollsionEndOverlap);\
	WidgetComponent->SetVisibility(false);
}

void AC_PickupItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AC_PickupItem::OnCollsionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AC_Player* player = Cast<AC_Player>(OtherActor))
	{
		player->SetPickupItem(this);
		WidgetComponent->SetVisibility(true);
	}
}

void AC_PickupItem::OnCollsionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (AC_Player* player = Cast<AC_Player>(OtherActor))
	{
		player->SetPickupItem(nullptr);
		WidgetComponent->SetVisibility(false);
	}
}

