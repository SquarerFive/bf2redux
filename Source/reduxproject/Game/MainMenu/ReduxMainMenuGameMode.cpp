// (C) Aiden Soedjarwo. 2019. Redux Project.


#include "ReduxMainMenuGameMode.h"
#include "Game/MainMenu/ReduxMainMenuHUD.h"

AReduxMainMenuGameMode::AReduxMainMenuGameMode()
{
	HUDClass = MainMenuHUD;
}

void AReduxMainMenuGameMode::PostLogin(APlayerController* NewPlayer)
{
	if (NewPlayer && MainMenuHUD)
	{
		NewPlayer->ClientSetHUD(MainMenuHUD);
	}
}