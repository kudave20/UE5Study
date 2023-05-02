// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorButton.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

ADoorButton::ADoorButton()
{
	PrimaryActorTick.bCanEverTick = false;

	OverlapBox = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapBox"));
	SetRootComponent(OverlapBox);
	OverlapBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	OverlapBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	OverlapBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	OverlapBox->SetMobility(EComponentMobility::Static);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetMobility(EComponentMobility::Static);

	PressText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("PressText"));
	PressText->SetupAttachment(RootComponent);
	PressText->SetVisibility(false);
}

void ADoorButton::BeginPlay()
{
	Super::BeginPlay();
	
	if (OverlapBox)
	{
		OverlapBox->OnComponentBeginOverlap.AddDynamic(this, &ADoorButton::OnOverlapBegin);
		OverlapBox->OnComponentEndOverlap.AddDynamic(this, &ADoorButton::OnOverlapEnd);
	}
}

void ADoorButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorButton::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (PressText)
	{
		PressText->SetVisibility(true);
	}
}

void ADoorButton::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (PressText)
	{
		PressText->SetVisibility(false);
	}
}

