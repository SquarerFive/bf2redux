// (C) Aiden Soedjarwo. 2019. Redux Project.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Static/ReduxLibrary.h"
#include "ReduxGameMode.generated.h"

/**
 * 
 */


class AReduxPlayer;

UCLASS()
class REDUXPROJECT_API AReduxGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project|Gamemode")
		EGamePresets GamePreset;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project|Gamemode")
		int32 NumTeams = 2;
	UFUNCTION(BlueprintCallable, Category = "ReduxProject|Gamemode")
		void StartConquest(
			EGameSize GameSize,
			int32 Tickets = 1000
		);
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReduxProject|Gamemode")
		TSubclassOf<AReduxPlayer> PlayerPawnClass;
	
private:
	UFUNCTION()
		void Autobalance();
	UFUNCTION()
		void GetPlayersInTeams();
};
