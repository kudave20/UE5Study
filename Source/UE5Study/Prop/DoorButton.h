// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorButton.generated.h"

UCLASS()
class UE5STUDY_API ADoorButton : public AActor
{
	GENERATED_BODY()
	
public:
	ADoorButton();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Button Properties")
	class UBoxComponent* OverlapBox;

	UPROPERTY(VisibleAnywhere, Category = "Button Properties")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Button Properties")
	class UTextRenderComponent* PressText;

	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

	UFUNCTION()
	void OnOverlapEnd(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex
	);

public:

};
