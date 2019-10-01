// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "reduxprojectGameMode.h"
#include "reduxprojectHUD.h"
#include "reduxprojectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AreduxprojectGameMode::AreduxprojectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/EpicGames/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AreduxprojectHUD::StaticClass();
	
}
