#include "Actors/Characters/C_Enemy.h"
#include "Actors/Items/PickupItems/Weapons/C_Projectile.h"
#include "Components/WidgetComponent.h"
#include "Widgets/C_EnemyWidget.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/TimelineComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Curves/CurveFloat.h"

AC_Enemy::AC_Enemy()
{
	PrimaryActorTick.bCanEverTick = true;

	FirePoint = CreateDefaultSubobject<USceneComponent>(TEXT("FirePoint"));
	FirePoint->SetupAttachment(RootComponent);
	FirePoint->SetRelativeLocation(FVector(90.0f, 0.f, 0.f));

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	WidgetComponent->SetupAttachment(RootComponent);
	WidgetComponent->SetDrawSize(FVector2D(100.f, 10.f));
	WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	WidgetComponent->SetRelativeLocation(FVector(0.f, 0.f, 85.f));

	Timeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Timeline"));

}

void AC_Enemy::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	Cast<UC_EnemyWidget>(WidgetComponent->GetWidget())->UpdateHealth(MaxHealth, Health);

	MaterialDynamic = GetMesh()->CreateDynamicMaterialInstance(0, GetMesh()->GetMaterial(0));
	GetMesh()->SetMaterial(0, MaterialDynamic);

	//FOnTimelineFloat timeline;
	//timeline.BindUFunction(this, "OnHitColor");
	//Timeline->AddInterpFloat(HitCurve, timeline);
	//Timeline->SetLooping(false);
}

void AC_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AC_Enemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AC_Enemy::TakeDamage(float damage, FDamageEvent const& event, AController* instigator, AActor* causer)
{
	float applydamage = Super::TakeDamage(damage, event, instigator, causer);

	Health = FMath::Clamp(Health - applydamage, 0.f, MaxHealth);

	if (Health <= 0.f)
	{
	}

	Cast<UC_EnemyWidget>(WidgetComponent->GetWidget())->UpdateHealth(MaxHealth, Health);

	Timeline->PlayFromStart();


	return applydamage;
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

void AC_Enemy::OnHitColor(float output)
{
	FLinearColor color = UKismetMathLibrary::LinearColorLerp(OriginColor, HitColor, output);
	MaterialDynamic->SetVectorParameterValue("FloorColor", color);
}

