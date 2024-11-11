#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileData.h"
#include "Tile.generated.h"

UCLASS()
class JUGGLERCPP_API ATile : public AActor
{
    GENERATED_BODY()

public:
    ATile();
    void SetTileData(const FTileData& Data);
    void FlipToBase(AActor* TargetBase);
    void PlayMatchEffect();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY()
    FTileData TileData;

    void ApplyMatchedMaterial();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tile", meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* MeshComponent;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tile", meta = (AllowPrivateAccess = "true"))
    UMaterialInterface* TileMaterial;

    void InitializeDefaults();
};
