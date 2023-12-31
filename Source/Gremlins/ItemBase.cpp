// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "GremlinsCharacter.h"
#include "GremlinsPlayerController.h"

// Sets default values
AItemBase::AItemBase()
{
	OverlapSphere = CreateDefaultSubobject<USphereComponent>(TEXT("OverlapSphere"));
	RootComponent = OverlapSphere;
	OverlapSphere->InitSphereRadius(100.0f);
	OverlapSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
	StaticMesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	StaticMesh->SetWorldScale3D(FVector(1.f));
	StaticMesh->SetCollisionProfileName(TEXT("NoCollision"));
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();

	OverlapSphere->OnComponentBeginOverlap.AddDynamic(this, &AItemBase::OnSphereBeginOverlap);
}

void AItemBase::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
									 int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	// Checking if it is a First Person Character overlapping
	AGremlinsCharacter* Character = Cast<AGremlinsCharacter>(OtherActor);
	if (Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		//OverlapSphere->OnComponentBeginOverlap.RemoveAll(this);

		// Display widget for pickup
	}
}

AGremlinsPlayerController* AItemBase::ConvertOverlapToPlayer(AActor* OtherActor)
{
	AGremlinsCharacter* Character = Cast<AGremlinsCharacter>(OtherActor);
	if (Character != nullptr)
	{
		return Cast<AGremlinsPlayerController>(Character->Controller);
		//Character->PickupObject();
	}
	return nullptr;
}

