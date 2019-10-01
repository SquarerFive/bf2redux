// (C) Aiden Soedjarwo. 2019. Redux Project.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ReduxMainMenuGameMode.generated.h"

/**
 * 
 */

class AReduxMainMenuHUD;

UCLASS()
class REDUXPROJECT_API AReduxMainMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()

		AReduxMainMenuGameMode();
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<AReduxMainMenuHUD> MainMenuHUD;
	virtual void PostLogin(APlayerController* NewPlayer) override;
};
