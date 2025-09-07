#include "NFGameMode.h"
#include "NFCharacter.h"
#include "Engine/World.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/DirectionalLight.h"
#include "Engine/SkyLight.h"

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
        // Spawn a simple floor slightly below the origin so the player starts above it
        AStaticMeshActor* Floor = World->SpawnActor<AStaticMeshActor>(FVector(0.f, 0.f, -90.f), FRotator::ZeroRotator, Params);
        if (Floor)
        {
            UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Plane.Plane"));
            if (Mesh)
            {
                Floor->GetStaticMeshComponent()->SetStaticMesh(Mesh);
                Floor->SetActorScale3D(FVector(10.f, 10.f, 1.f));
            }
        }

        // Basic lighting so the scene is visible
        World->SpawnActor<ADirectionalLight>(FVector(0.f, 0.f, 300.f), FRotator(-45.f, 0.f, 0.f), Params);
        World->SpawnActor<ASkyLight>(FVector::ZeroVector, FRotator::ZeroRotator, Params);
    }
}

