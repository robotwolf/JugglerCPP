#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoardManager.generated.h"

class ATile;
class ABase;

UCLASS()
class JUGGLERCPP_API ABoardManager : public AActor
{
    GENERATED_BODY()

public:
    ABoardManager();
    void InitializeBoard();
    void ShuffleDeck();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere, Category = "Setup")
    TSubclassOf<ATile> TileClass;

    UPROPERTY(VisibleAnywhere)
    TArray<ATile*> Tiles;

    UPROPERTY(VisibleAnywhere)
    TArray<ABase*> Bases;

    UPROPERTY(VisibleAnywhere)
    ATile* HomelessTile;

    UPROPERTY(EditAnywhere, Category = "Effects")
    UParticleSystem* FlipEffect;

    UPROPERTY(EditAnywhere, Category = "Audio")
    USoundBase* MatchSound;
};
