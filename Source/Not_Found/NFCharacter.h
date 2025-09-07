#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NFCharacter.generated.h"

UCLASS()
class NOT_FOUND_API ANFCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ANFCharacter();

protected:
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void MoveForward(float Value);
    void MoveRight(float Value);
    void Turn(float Value);
    void LookUp(float Value);

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
    class USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
    class UCameraComponent* FollowCamera;
};

