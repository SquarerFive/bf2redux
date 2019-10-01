// (C) Aiden Soedjarwo. 2019. Redux Project.


#include "ReduxPlayArea.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
// Sets default values
AReduxPlayArea::AReduxPlayArea()
{
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialFinder(TEXT("/Game/ReduxProject/Materials/Minimap/M_PlayAreaMasked_Inst"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshFinder(TEXT("/Game/EpicGames/Geometry/Meshes/1M_Cube"));
	Material = MaterialFinder.Object;
	Mesh = MeshFinder.Object;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayMesh"));
	if (Mesh)
	{
		MeshComp->SetStaticMesh(Mesh);
		if (Material)
			MeshComp->SetMaterial(-1, Material);
		MeshComp->SetCastShadow(false);
	}
	MeshComp->SetupAttachment(RootComponent);
	MeshComp->SetRelativeTransform(MeshTransform);
}

// Called when the game starts or when spawned
void AReduxPlayArea::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReduxPlayArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AReduxPlayArea::Refresh()
{
	if (Mesh)
	{
		MeshComp->SetStaticMesh(Mesh);
		if (Material)
			MeshComp->SetMaterial(0, Material);
		MeshComp->SetRelativeScale3D(MeshTransform.GetScale3D());
		//MeshComp->SetupAttachment(RootComponent);
		MeshComp->SetCastShadow(false);
	}

}

void AReduxPlayArea::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
}