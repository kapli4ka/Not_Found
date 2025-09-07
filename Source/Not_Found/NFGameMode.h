#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NFGameMode.generated.h"

UCLASS()
class NOT_FOUND_API ANFGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ANFGameMode();
    virtual void BeginPlay() override;
};

