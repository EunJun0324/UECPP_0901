#include "Actors/Characters/C_Player.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/C_CombatComponent.h"

AC_Player::AC_Player()
{
	PrimaryActorTick.bCanEverTick = true;
    
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 400.0f;
    SpringArm->bUsePawnControlRotation = true; 

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    Camera->bUsePawnControlRotation = false; 

    bUseControllerRotationYaw = true;
    GetCharacterMovement()->bOrientRotationToMovement = false;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

    CombatComponent = CreateDefaultSubobject<UC_CombatComponent>(TEXT("CombatComponent"));
}

void AC_Player::BeginPlay()
{
	Super::BeginPlay();

    if (APlayerController* PC = Cast<APlayerController>(Controller))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            if (MappingContext)
            {
                Subsystem->AddMappingContext(MappingContext, 0);
            }
        }
    }

    SetWalkSpeed();
}

void AC_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AC_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInput->BindAction(MoveAction     , ETriggerEvent::Triggered, this, &ThisClass::Move     );
        EnhancedInput->BindAction(LookAction     , ETriggerEvent::Triggered, this, &ThisClass::Look     );
        EnhancedInput->BindAction(JumpAction     , ETriggerEvent::Started  , this, &ThisClass::Jump     );
        EnhancedInput->BindAction(InteractAction , ETriggerEvent::Started  , this, &ThisClass::Interact );
        EnhancedInput->BindAction(AimAction      , ETriggerEvent::Started  , this, &ThisClass::Aiming   );
        EnhancedInput->BindAction(AimAction      , ETriggerEvent::Completed, this, &ThisClass::Aiming   );
        EnhancedInput->BindAction(FireAction     , ETriggerEvent::Started  , this, &ThisClass::Firing   );
        EnhancedInput->BindAction(FireAction     , ETriggerEvent::Completed, this, &ThisClass::Firing   );
        EnhancedInput->BindAction(RunAction      , ETriggerEvent::Started  , this, &ThisClass::Run      );
        EnhancedInput->BindAction(RunAction      , ETriggerEvent::Completed, this, &ThisClass::Run      );
        EnhancedInput->BindAction(AutomaticAction, ETriggerEvent::Started  , this, &ThisClass::Automatic);
        EnhancedInput->BindAction(ReloadAction   , ETriggerEvent::Started  , this, &ThisClass::Reload   );
    }
}

void AC_Player::Move(const FInputActionValue& value)
{
    const FVector2D Movementvector = value.Get<FVector2D>();

    const FRotator Rotation = Controller->GetControlRotation();
    const FRotator YawRotation(0, Rotation.Yaw, 0);

    const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    AddMovementInput(ForwardDirection, Movementvector.X);
    AddMovementInput(RightDirection, Movementvector.Y);
}

void AC_Player::Look(const FInputActionValue& value)
{
    const FVector2D LookAxisvector = value.Get<FVector2D>();

    AddControllerYawInput(LookAxisvector.X);
    AddControllerPitchInput(LookAxisvector.Y);
}

void AC_Player::Jump(const FInputActionValue& value)
{
    Super::Jump();
}

void AC_Player::Interact(const FInputActionValue& value)
{
    if (NearPickItem == nullptr) return;

    if (CombatComponent->PickupItem(NearPickItem))
    {
        NearPickItem = nullptr;
    }
}

void AC_Player::Aiming(const FInputActionValue& value)
{
    bool bAiming = value.Get<bool>();

    CombatComponent->SetAiming(bAiming);

    if (bAiming)
    {
        SetWalkSpeed();
    }
}

void AC_Player::Firing(const FInputActionValue& value)
{
    bool bFiring = value.Get<bool>();

    CombatComponent->Firing(bFiring);

    if (bFiring)
    {
        SetWalkSpeed();
    }
}

void AC_Player::Automatic(const FInputActionValue& value)
{
    CombatComponent->ToggleAutomatic();
}

void AC_Player::Run(const FInputActionValue& value)
{
    bool bAutomaic = value.Get<bool>();

    if (bAutomaic) { SetRunSpeed(); }
    else           { SetWalkSpeed(); }
}

void AC_Player::Reload(const FInputActionValue& value)
{
    CombatComponent->Reload();
}

void AC_Player::SetRunSpeed()
{
    GetCharacterMovement()->MaxWalkSpeed = 600;
}

void AC_Player::SetWalkSpeed()
{
    GetCharacterMovement()->MaxWalkSpeed = 400;
}

