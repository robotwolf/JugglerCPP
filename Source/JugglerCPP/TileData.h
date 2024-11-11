#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TileData.generated.h"

// Forward declare particle and sound assets for tile flip effects
class UMaterialInterface;
class UParticleSystem;
class USoundBase;

USTRUCT(BlueprintType)
struct FTileData
{
    GENERATED_BODY()

    // A unique ID that matches the tile to a base
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile")
    int32 MatchingID;

    // Material applied to the tile when it's correctly matched with its base
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile")
    UMaterialInterface* MatchedMaterial;

    // Particle effect to play when flipping to a base
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
    UParticleSystem* FlipParticleEffect;

    // Sound effect for a successful match
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
    USoundBase* MatchSoundEffect;

    // Constructor with default values
    FTileData()
        : MatchingID(-1),  // Default to -1 to indicate no match
        MatchedMaterial(nullptr),
        FlipParticleEffect(nullptr),
        MatchSoundEffect(nullptr)
    {
    }
};
