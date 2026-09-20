#include "Actors/Items/PickupItems/Weapons/C_Weapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Actors/Characters/C_Player.h"
#include "Components/SphereComponent.h"

AC_Weapon::AC_Weapon()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetSimulatePhysics(true);
}

void AC_Weapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void AC_Weapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*
	FString str;
	FName name;
	FText text;

	// FName -> FString
	str = name.ToString();
	// FText-> FSTring
	str = text.ToString();

	// FString -> FName
	name = FName(*str);
	// FText -> FName
	name = FName(*text.ToString());

	// FString -> FText
	text = FText::FromString(str);

	// FName -> FText
	text = FText::FromName(name);
	*/

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

