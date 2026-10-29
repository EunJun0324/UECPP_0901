#include "Actors/Items/SpawnItems/C_SpawnItem.h"
#include "Actors/Items/SpawnItems/C_SpawnPad.h"
#include "Actors/Characters/C_Player.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/C_BuffComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"

AC_SpawnItem::AC_SpawnItem()
{
	PrimaryActorTick.bCanEverTick = true;
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collsion"));
	SetRootComponent(Collision);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collision);
}

void AC_SpawnItem::BeginPlay()
{
	Super::BeginPlay();
	
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AC_SpawnItem::OnCollsionBeginOverlap);
}

void AC_SpawnItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorRotation(FRotator(0.f, GetActorRotation().Yaw + DeltaTime * RotateSpeed, 0.f));
}

void AC_SpawnItem::OnCollsionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AC_Player* player = Cast<AC_Player>(OtherActor);

	if (player == nullptr) return;

	player->GetBuffComponent()->Buff(Type, Value);
	
	UNiagaraFunctionLibrary::SpawnSystemAttached(Particle, OtherComp, FName(), FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::SnapToTarget, true);

	Cast<AC_SpawnPad>(GetOwner())->StartSpawnTimer();
	
	Destroy();
}

