#include "Tile.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"

ATile::ATile()
{
    PrimaryActorTick.bCanEverTick = false;
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    SetRootComponent(MeshComponent);
}

void ATile::BeginPlay()
{
    Super::BeginPlay();
    InitializeDefaults();
    // Add any initialization code here
}

void ATile::SetTileData(const FTileData& Data)
{
    TileData = Data;
}

void ATile::FlipToBase(AActor* TargetBase)
{
    FVector StartLocation = GetActorLocation();
    FVector TargetLocation = TargetBase->GetActorLocation();
    SetActorLocation(FMath::VInterpTo(StartLocation, TargetLocation, GetWorld()->GetDeltaSeconds(), 3.0f));

    if (TileData.FlipParticleEffect)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TileData.FlipParticleEffect, GetActorLocation());
    }
}

void ATile::PlayMatchEffect()
{
    ApplyMatchedMaterial();

    if (TileData.MatchSoundEffect)
    {
        UGameplayStatics::PlaySoundAtLocation(this, TileData.MatchSoundEffect, GetActorLocation());
    }
}

void ATile::ApplyMatchedMaterial()
{
    if (TileData.MatchedMaterial)
    {
        if (MeshComponent)
        {
            MeshComponent->SetMaterial(0, TileData.MatchedMaterial);
        }
    }
}

void ATile::InitializeDefaults()
{
    // Set default material and mesh if not already set
    if (!MeshComponent->GetMaterial(0))
    {
        // Replace with your default material
        MeshComponent->SetMaterial(0, LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/DefaultPath/DefaultMaterial.DefaultMaterial")));
    }
    if (!MeshComponent->GetStaticMesh())
    {
        // Replace with your default mesh
        MeshComponent->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Game/DefaultPath/DefaultMesh.DefaultMesh")));
    }
}
