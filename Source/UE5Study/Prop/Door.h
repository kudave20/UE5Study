// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeometryCollection/GeometryCollectionActor.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class UE5STUDY_API ADoor : public AGeometryCollectionActor
{
	GENERATED_BODY()
public:
	void Explode();

private:
	UPROPERTY(EditAnywhere, Category = "Explosion")
	class UParticleSystem* Explosion;

	UPROPERTY(EditAnywhere, Category = "Explosion")
	class USoundCue* ExplosionSound;

	UPROPERTY(EditAnywhere, Category = "Explosion")
	TSubclassOf<class AFieldSystemActor> MasterField;
};
