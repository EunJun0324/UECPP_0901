#include "Actors/Items/PickupItems/Weapons/C_Rifle.h"
#include "Engine/SkeletalMeshSocket.h"

void AC_Rifle::Fire(const FVector& hitTaghet)
{
	Super::Fire(hitTaghet);

	const USkeletalMeshSocket* muzzleSocket = Mesh->GetSocketByName(FName("Muzzle"));

	if (muzzleSocket != nullptr)
	{
		FTransform transform = muzzleSocket->GetSocketTransform(Mesh);
		FRotator targetRoation = (hitTaghet - transform.GetLocation()).Rotation();

		SpawnProjectile(transform.GetLocation(), targetRoation);
	}
}
