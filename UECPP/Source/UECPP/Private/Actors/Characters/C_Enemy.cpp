#include "Actors/Characters/C_Enemy.h"
#include "Actors/Items/PickupItems/Weapons/C_Projectile.h"

AC_Enemy::AC_Enemy()
{
	PrimaryActorTick.bCanEverTick = true;

	FirePoint = CreateDefaultSubobject<USceneComponent>(TEXT("FirePoint"));
	FirePoint->SetupAttachment(RootComponent);
	FirePoint->SetRelativeLocation(FVector(90.0f, 0.f, 0.f));
}

void AC_Enemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void AC_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AC_Enemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AC_Enemy::Fire(AActor* target)
{
	FRotator dir = (target->GetActorLocation() - GetActorLocation()).GetSafeNormal().Rotation();

	if (UWorld* world = GetWorld())
	{
		FActorSpawnParameters spawnParam;
		spawnParam.Owner = this;
		spawnParam.Instigator = this;

		world->SpawnActor<AC_Projectile>(
			ProjectileClass,
			FirePoint->GetComponentLocation(),
			dir,
			spawnParam
		);
	}
}

