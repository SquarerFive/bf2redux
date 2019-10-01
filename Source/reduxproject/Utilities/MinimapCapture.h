// (C) Aiden Soedjarwo. 2019. Redux Project.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/SceneCapture2D.h"
#include "MinimapCapture.generated.h"

/**
 * 
 */
UCLASS()
class REDUXPROJECT_API AMinimapCapture : public ASceneCapture2D
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Redux Project|Minimap")
		void CaptureMinimap(UTextureRenderTarget2D* Texture, float Width, ESceneCaptureSource MapCaptureType, UMaterialInterface* MapMaterial);
};
