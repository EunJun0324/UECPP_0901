#include "Actors/Items/PickupItems/Weapons/C_Casing.h"

AC_Casing::AC_Casing()
{
	PrimaryActorTick.bCanEverTick = true;
	CasingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(CasingMesh);

	CasingMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	CasingMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CasingMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	CasingMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	CasingMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	CasingMesh->SetSimulatePhysics(true);
	CasingMesh->SetEnableGravity(true);
	CasingMesh->SetNotifyRigidBodyCollision(true);


}

void AC_Casing::BeginPlay()
{
	Super::BeginPlay();
	
	SetLifeSpan(5.0f);
	CasingMesh->AddImpulse(GetActorForwardVector() * 5);
}


