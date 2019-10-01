// (C) Aiden Soedjarwo. 2019. Redux Project.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Static/ReduxLibrary.h"
#include "ReduxPlayerState.generated.h"

/**
 * 
 */

class UReduxSpawnableComp;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerBasicUpdate);

UCLASS()
class REDUXPROJECT_API AReduxPlayerState : public APlayerState
{
	GENERATED_BODY()
		virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	/* Team */
	UPROPERTY(BlueprintReadOnly, Replicated, Category = "Redux Project|PlayerState")
		int32 Team;
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation, Category = "Redux Project|PlayerState")
		void ChangeTeam(int32 NewTeam);

	/* Spawning */
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Redux Project|PlayerState")
		UReduxSpawnableComp* SpawnLoc;
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation, Category = "Redux Project|PlayerState")
		void SetSpawn(UReduxSpawnableComp * SpawnActorComp);

	/* Delegates */
	UPROPERTY(BlueprintReadWrite, BlueprintCallable, BlueprintAssignable, Category = "Redux Project|PlayerState")
		FOnPlayerBasicUpdate OnPlayerBasicUpdate;

	/* Send updates from server to clients */
	UFUNCTION(NetMulticast, Reliable)
		void SendUpdatesToClients();
};
