#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base.generated.h"

class ATile;

UCLASS()
class JUGGLERCPP_API ABase : public AActor
{
    GENERATED_BODY()

public:
    ABase();
    bool IsOccupied() const;
    void SetOccupyingTile(ATile* Tile);

    FORCEINLINE int32 GetMatchingID() const { return MatchingID; }
    FORCEINLINE void SetMatchingID(int32 ID) { MatchingID = ID; }

    UFUNCTION(BlueprintCallable)
    UMaterialInterface* GetMatchedMaterial() const;

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base", meta = (AllowPrivateAccess = "true"))
    int32 MatchingID;

    UPROPERTY()
    ATile* OccupyingTile;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base", meta = (AllowPrivateAccess = "true"))
    UMaterialInterface* MatchedMaterial;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base", meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* BaseMeshComponent;

    void InitializeDefaults();
};
