#include "AI/MyAIActor.h"

#include "AI/MyAISubsystem.h"
#include "Components/SphereComponent.h"

AMyAIActor::AMyAIActor()
{
	//create the sphere component
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));

	//set the root component
	SetRootComponent(SphereComponent);
}

void AMyAIActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UMyAISubsystem::ResolveOverlap(this, OtherActor, OverlappedComponent, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}


void AMyAIActor::BeginPlay()
{
	//call the parent implementation
	Super::BeginPlay();

	//set up the onhit function for the sphere component
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AMyAIActor::OnBeginOverlap);
}
