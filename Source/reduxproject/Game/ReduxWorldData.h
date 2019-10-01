// (C) Aiden Soedjarwo. 2019. Redux Project.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "Static/ReduxLibrary.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Utilities/MinimapCapture.h"
#include "Engine/SceneCapture2D.h"
#include "Engine/EngineTypes.h"
#include "ReduxWorldData.generated.h"

/**
 * 
 */
class AReduxPlayArea;
UCLASS()
class REDUXPROJECT_API AReduxWorldData : public AWorldSettings
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Redux Project", meta = (AllowPrivateAccess = "true"))
		FName MapName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Redux Project")
		UTexture2D* MapBackground;

	/* Team Setup */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Redux Project|Teams", meta = (AllowPrivateAccess = "true"))
		TArray<FTeamData> TeamData;

	/* Minimap */
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Redux Project", meta = (AllowPrivateAccess = "true"))
		UTextureRenderTarget2D * MinimapTexture;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project", meta = (AllowPrivateAccess = "true"))
		UTextureRenderTarget2D * MinimapTexture_UnMasked;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project", meta = (AllowPrivateAccess = "true"))
		float MinimapWidth = 2500.f;
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Redux Project", meta = (AllowPrivateAccess = "true"))
		void CreateMinimap();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project", meta = (AllowPrivateAccess = "true"))
		FTransform CameraTransform = FTransform(FRotator(-90.f), FVector(0.f, 0.f, 5000.f), FVector(1.f));
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project", meta = (AllowPrivateAccess = "true"))
		TEnumAsByte<ESceneCaptureSource> MapCaptureType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project", meta = (AllowPrivateAccess = "true"))
		UMaterialInterface * MinimapMaterial;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project", meta = (AllowPrivateAccess = "true"))
		TArray<AReduxPlayArea*> PlayAreaVolumes;
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Redux Project", meta = (AllowPrivateAccess = "true"))
		void AutoAdjustToActor();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project", meta = (AllowPrivateAccess = "true"))
		AActor * AdjustmentActor;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project", meta = (AllowPrivateAccess = "true"))
		UTexture2D * FriendlyFlagTexture;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project", meta = (AllowPrivateAccess = "true"))
		UTexture2D * EnemyFlagTexture;
public:
	UFUNCTION(BlueprintCallable, Category = "Redux Project", meta = (AllowPrivateAccess = "true"))
		float GetMinimapWidth();
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Redux Project", meta = (AllowPrivateAccess = "true"))
		void RenderMinimap(UTextureRenderTarget2D * RenderTarget, UTextureRenderTarget2D * RenderTarget_NoMask, UMaterialInstanceDynamic* Material);
};
