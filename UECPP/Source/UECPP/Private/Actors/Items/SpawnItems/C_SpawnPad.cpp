#include "Actors/Items/SpawnItems/C_SpawnPad.h"
#include "Actors/Items/SpawnItems/C_SpawnItem.h"
#include "Components/StaticMeshComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"

AC_SpawnPad::AC_SpawnPad()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponent"));
	NiagaraComponent->SetupAttachment(Mesh);
}

void AC_SpawnPad::BeginPlay()
{
	Super::BeginPlay();

	StartSpawnTimer();
}

void AC_SpawnPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AC_SpawnPad::StartSpawnTimer()
{
	GetWorldTimerManager().SetTimer
	(
		SpawnTimer,
		this,
		&ThisClass::SpawnTimerFunction,
		5.f,
		false
	);

	NiagaraComponent->Deactivate();
	NiagaraComponent->SetAsset(CreatingParticle);
	NiagaraComponent->Activate();
}

void AC_SpawnPad::SpawnTimerFunction()
{
	NiagaraComponent->Deactivate();
	NiagaraComponent->SetAsset(CreatedParticle);
	NiagaraComponent->Activate();

	FVector loc = GetActorLocation();
	loc.Z = ZOffset;

	FActorSpawnParameters param;
	param.Owner = this;

	GetWorld()->SpawnActor<AC_SpawnItem>(SpawnItemClass, loc, FRotator::ZeroRotator, param);
}