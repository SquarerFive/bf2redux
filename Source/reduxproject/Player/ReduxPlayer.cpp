// (C) Aiden Soedjarwo. 2019. Redux Project.


#include "ReduxPlayer.h"

// Sets default values
AReduxPlayer::AReduxPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AReduxPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReduxPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AReduxPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

