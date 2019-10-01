// (C) Aiden Soedjarwo. 2019. Redux Project.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ReduxPlayer.generated.h"


UCLASS()
class REDUXPROJECT_API AReduxPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AReduxPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
};
