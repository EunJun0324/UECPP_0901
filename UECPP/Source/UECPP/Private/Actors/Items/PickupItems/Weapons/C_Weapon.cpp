#include "Actors/Items/PickupItems/Weapons/C_Weapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Actors/Characters/C_Player.h"
#include "Components/SphereComponent.h"
#include "Components/TimelineComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Actors/Items/PickupItems/Weapons/C_Projectile.h"

AC_Weapon::AC_Weapon()
{
	PrimaryActorTick.bCanEverTick = true;

	{
		Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
		Mesh->SetupAttachment(RootComponent);
		Mesh->SetSimulatePhysics(true);
	}

	{
		Timeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Timeline"));
	}
}

void AC_Weapon::BeginPlay()
{
	Super::BeginPlay();
	
	{
		FOnTimelineFloat timeline;
		timeline.BindUFunction(this, "OnAiming");
		Timeline->AddInterpFloat(AimCurve, timeline);
		Timeline->SetLooping(false);
	}

}

void AC_Weapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AC_Weapon::Equip(ACharacter* character)
{
	if (character == nullptr) return;

	OwnerCharacter = character;
	SetOwner(character);

	Mesh->SetSimulatePhysics(false);

	FAttachmentTransformRules attachRules(EAttachmentRule::SnapToTarget, true);
	Mesh->AttachToComponent(Collision, attachRules);
	AttachToComponent(OwnerCharacter->GetMesh(), attachRules, SocketName);

	Collision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AC_Weapon::UnEquip()
{
	FDetachmentTransformRules detachRules(EDetachmentRule::KeepWorld, true);
	DetachFromActor(detachRules);

	OwnerCharacter = nullptr;

	Collision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetSimulatePhysics(true);
	SetOwner(nullptr);
}

void AC_Weapon::Aiming(bool bAiming)
{
	if (bAiming)
	{
		Timeline->PlayFromStart();
		SetAimData(AimData);
	}
	else
	{
		Timeline->ReverseFromEnd();
		SetAimData(BaseData);
	}
}

void AC_Weapon::SetAimData(FWeaponAimData aimData)
{
	USpringArmComponent* springArm = Cast<AC_Player>(GetOwner())->GetSpringArm();
	springArm->TargetArmLength = aimData.TargetArmLength;
	springArm->SocketOffset = aimData.SocketOffset;
	springArm->bEnableCameraLag = aimData.bCameraLag;
}

void AC_Weapon::Fire(const FVector& hitTaghet)
{
	{
		if (AMMO <= 0) return;

		const USkeletalMeshSocket* muzzleSocket = Mesh->GetSocketByName(FName("Muzzle"));
		
		if (muzzleSocket != nullptr)
		{
			FTransform transform = muzzleSocket->GetSocketTransform(Mesh);
			FRotator targetRoation = (hitTaghet - transform.GetLocation()).Rotation();

			SpawnProjectile(transform.GetLocation(), targetRoation);
		}

		AMMO--;
	}
}

void AC_Weapon::Reload(int32& ammo)
{
	const int32 needAMMO = MagazineCapacity - AMMO;

	if (needAMMO <= 0 || ammo <= 0) return;

	const int32 loadAMMO = FMath::Min(needAMMO, ammo);

	AMMO += loadAMMO;
	ammo -= loadAMMO;
}

void AC_Weapon::SpawnProjectile(const FVector & spawnLocation, const FRotator & direction)
{
	APawn* instigatorPawn = Cast<APawn>(GetOwner());

	if (instigatorPawn == nullptr || ProjectileClass == nullptr) return;

	if (UWorld* world = GetWorld())
	{
		FActorSpawnParameters spawnParam;
		spawnParam.Owner = GetOwner();
		spawnParam.Instigator = instigatorPawn;

		world->SpawnActor<AC_Projectile>(
			ProjectileClass,
			spawnLocation,
			direction,
			spawnParam
		);
	}
}

void AC_Weapon::OnAiming(float output)
{
	float fov = FMath::Lerp(AimData.FieldofView, BaseData.FieldofView, output);
	Cast<AC_Player>(GetOwner())->GetCamera()->SetFieldOfView(fov);
}

