#include "NFGameMode.h"
#include "NFCharacter.h"
#include "Engine/World.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"

ANFGameMode::ANFGameMode()
{
    DefaultPawnClass = ANFCharacter::StaticClass();
}

void ANFGameMode::BeginPlay()
{
    Super::BeginPlay();

    if (UWorld* World = GetWorld())
    {
        FActorSpawnParameters Params;
        AStaticMeshActor* Floor = World->SpawnActor<AStaticMeshActor>(FVector::ZeroVector, FRotator::ZeroRotator, Params);
        if (Floor)
        {
            UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Plane.Plane"));
            if (Mesh)
            {
                Floor->GetStaticMeshComponent()->SetStaticMesh(Mesh);
                Floor->SetActorScale3D(FVector(10.f, 10.f, 1.f));
            }
        }
    }
}

