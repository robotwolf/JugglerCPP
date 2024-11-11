#include "Base.h"
#include "Tile.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"

ABase::ABase()
{
    PrimaryActorTick.bCanEverTick = false;
    OccupyingTile = nullptr;
    MatchedMaterial = nullptr;  // Initialize MatchedMaterial
    BaseMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMeshComponent"));
    SetRootComponent(BaseMeshComponent);
}

void ABase::BeginPlay()
{
    Super::BeginPlay();
    InitializeDefaults();
}

bool ABase::IsOccupied() const
{
    return OccupyingTile != nullptr;
}

void ABase::SetOccupyingTile(ATile* Tile)
{
    OccupyingTile = Tile;
}

UMaterialInterface* ABase::GetMatchedMaterial() const
{
    return MatchedMaterial;
}

void ABase::InitializeDefaults()
{
    // Set default material and mesh if not already set
    if (!BaseMeshComponent->GetMaterial(0))
    {
        // Replace with your default material
        BaseMeshComponent->SetMaterial(0, LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/DefaultPath/DefaultMaterial.DefaultMaterial")));
    }
    if (!BaseMeshComponent->GetStaticMesh())
    {
        // Replace with your default mesh
        BaseMeshComponent->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Game/DefaultPath/DefaultMesh.DefaultMesh")));
    }
}
