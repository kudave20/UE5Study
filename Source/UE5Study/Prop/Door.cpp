// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Field/FieldSystemActor.h"

void ADoor::Explode()
{
	if (Explosion)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, Explosion, GetActorLocation(), GetActorRotation(), FVector(2.f));
	}
	if (ExplosionSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ExplosionSound, GetActorLocation());
	}
	UWorld* World = GetWorld();
	if (World && MasterField)
	{
		World->SpawnActor<AFieldSystemActor>(MasterField, GetActorTransform());
	}
	SetLifeSpan(3.f);
}