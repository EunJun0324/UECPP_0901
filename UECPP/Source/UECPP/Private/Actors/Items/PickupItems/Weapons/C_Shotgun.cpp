#include "Actors/Items/PickupItems/Weapons/C_Shotgun.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Kismet/KismetMathLibrary.h"

void AC_Shotgun::Fire(const FVector& hitTaghet)
{
	Super::Fire(hitTaghet);

	const USkeletalMeshSocket* muzzleSocket = Mesh->GetSocketByName(FName("Muzzle"));

	if (muzzleSocket != nullptr)
	{
		FTransform transform = muzzleSocket->GetSocketTransform(Mesh);

		FVector dir = (hitTaghet - transform.GetLocation()).GetSafeNormal();
		
		for (int i = 0; i < SpreadCount; i++)
		{
			FRotator targetRoation = UKismetMathLibrary::RandomUnitVectorInConeInDegrees(dir, SpreadAngle).Rotation();

			SpawnProjectile(transform.GetLocation(), targetRoation);
		}
	}
}
