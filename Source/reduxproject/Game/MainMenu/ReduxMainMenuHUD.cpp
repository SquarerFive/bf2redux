// (C) Aiden Soedjarwo. 2019. Redux Project.


#include "ReduxMainMenuHUD.h"
#include "GameFramework/PlayerController.h"
void AReduxMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();
	PlayerOwner->bShowMouseCursor = true;
	PlayerOwner->SetInputMode(FInputModeUIOnly());
}