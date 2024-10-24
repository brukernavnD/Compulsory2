#include "AI/MyAIActor.h"

#include "AI/MyAISubsystem.h"
#include "Components/SphereComponent.h"
#include "Health/DamageComponent.h"
#include "Health/HealthComponent.h"

AMyAIActor::AMyAIActor()
{
	//initialize the sphere component
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));

	//set the root component
	SetRootComponent(SphereComponent);

	//initialize the mesh component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	//setup the attatchment for the meshcomponent
	MeshComponent->SetupAttachment(SphereComponent);

	//initialize non moveable components
	DamageComponent = CreateDefaultSubobject<UDamageComponent>(TEXT("DamageComponent"));
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
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
