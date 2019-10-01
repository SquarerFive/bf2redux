// (C) Aiden Soedjarwo. 2019. Redux Project.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Static/ReduxLibrary.h"
#include "ReduxGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class REDUXPROJECT_API UReduxGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FGameUISettings GameUISettings;

	UPROPERTY(BlueprintReadOnly)
		TArray<FLogUIType> DebugLogs;

};
