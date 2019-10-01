// (C) Aiden Soedjarwo. 2019. Redux Project.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/TextureRenderTarget2D.h"
#include "ReduxController.generated.h"

/**
 * 
 */
class AReduxWorldData;
class AReduxPlayerState;
class UReduxSpawnableComp;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMinimapTextureUpdated, UMaterialInstanceDynamic*, MinimapMaterial);
UCLASS()
class REDUXPROJECT_API AReduxController : public APlayerController
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadOnly, Category = "Redux Project|Minimap")
		UTextureRenderTarget2D* LocalMinimapTexture;
	UPROPERTY(BlueprintReadOnly, Category = "Redux Project|Minimap")
		UTextureRenderTarget2D* LocalMinimapTexture_NoMask;
	UPROPERTY(BlueprintReadOnly, Category = "Redux Project")
		AReduxWorldData* ReduxWorldData;
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project|Minimap")
		UMaterialInterface* LocalMinimapMaterial;
	UPROPERTY(BlueprintReadWrite, Category = "Redux Project|Minimap")
		UMaterialInstanceDynamic* LocalMinimapMaterial_Dynamic;
	/* Local Functions */

	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Redux Project")
		FOnMinimapTextureUpdated OnMinimapTextureUpdatedDelegate;

	UFUNCTION(BlueprintCallable, Category = "Redux Project|Minimap")
		void CreateMinimapTexture(int32 Width = 0, int32 Height = 0);

	UFUNCTION(BlueprintCallable, Category = "Redux Project")
		void SwitchTeams();

	UFUNCTION(Server, Reliable, WithValidation)
		void SwitchTeams_Internal();

	UFUNCTION(BlueprintPure, Category = "Redux Project")
		AReduxPlayerState* GetMyPlayerState();
	UPROPERTY()
		AReduxPlayerState* MyPlayerState;

	UFUNCTION(BlueprintCallable, Category = "Redux Project")
		void SetSpawn(UReduxSpawnableComp* Spawn);

	UFUNCTION(Server, Reliable, WithValidation)
		void SetSpawn_Internal(UReduxSpawnableComp* Spawn);

	UFUNCTION(Client, BlueprintCallable, UnReliable)
		void CallClientUpdate();
	UFUNCTION(BlueprintNativeEvent)
		void OnClientUpdate();
};
