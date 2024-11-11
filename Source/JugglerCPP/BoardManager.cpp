#include "BoardManager.h"
#include "Tile.h"
#include "Base.h"
#include "TileData.h"
#include "Kismet/GameplayStatics.h"

ABoardManager::ABoardManager()
{
    PrimaryActorTick.bCanEverTick = false;
    HomelessTile = nullptr;  // Initialize pointers
    FlipEffect = nullptr;
    MatchSound = nullptr;
}

void ABoardManager::BeginPlay()
{
    Super::BeginPlay();
    InitializeBoard();
}

void ABoardManager::InitializeBoard()
{
    for (ABase* Base : Bases)
    {
        if (Base)
        {
            FActorSpawnParameters SpawnParams;
            SpawnParams.Owner = this;
            FVector SpawnLocation = Base->GetActorLocation();
            ATile* SpawnedTile = GetWorld()->SpawnActor<ATile>(TileClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
            if (SpawnedTile)
            {
                FTileData TileData;
                TileData.MatchingID = Base->GetMatchingID();
                TileData.MatchedMaterial = Base->GetMatchedMaterial();
                TileData.FlipParticleEffect = FlipEffect;
                TileData.MatchSoundEffect = MatchSound;
                SpawnedTile->SetTileData(TileData);
                Tiles.Add(SpawnedTile);
            }
        }
    }
}

void ABoardManager::ShuffleDeck()
{
    // Implement your shuffle logic here
}
