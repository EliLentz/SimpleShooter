// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
	AGun* Gun;

	UPROPERTY(EditAnywhere, Category = "Input", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* MappingContext;
	UPROPERTY(EditAnywhere, Category = "Input", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ShootAction;
	UPROPERTY(EditAnywhere, Category = "Input", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, Category = "Input", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;
	UPROPERTY(EditAnywhere, Category = "Input", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	UPROPERTY()
	APlayerController* PlayerController;

	void Shoot(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Move(const FInputActionValue& Value);
};
