// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "ItemBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPickUp, AGremlinsCharacter*, PickUpCharacter);

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GREMLINS_API AItemBase : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	USphereComponent* OverlapSphere;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	UStaticMesh* Mesh;

	UPROPERTY(BlueprintAssignable, Category = Interaction)
	FPickUp OnPickUp;

	// Sets default values for this actor's properties
	AItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* StaticMesh;

	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
							  int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};


