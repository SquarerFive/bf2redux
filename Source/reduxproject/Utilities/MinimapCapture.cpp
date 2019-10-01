// (C) Aiden Soedjarwo. 2019. Redux Project.


#include "MinimapCapture.h"
#include "Engine/Classes/Materials/Material.h"
#include "Engine/Classes/Materials/MaterialInstanceDynamic.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Engine/Classes/Components/SceneCaptureComponent2D.h"


void AMinimapCapture::CaptureMinimap(UTextureRenderTarget2D* Texture, float Width, ESceneCaptureSource MapCaptureType, UMaterialInterface* MapMaterial)
{
	
	USceneCaptureComponent2D* SceneCapture2D = GetCaptureComponent2D();
	if (SceneCapture2D)
	{
		SceneCapture2D->ProjectionType = ECameraProjectionMode::Orthographic;
		SceneCapture2D->OrthoWidth = Width;
		SceneCapture2D->CaptureSource = MapCaptureType;
		if (!Texture && !MapMaterial)
		{
			return;
		}
		SceneCapture2D->TextureTarget = Texture;
		SceneCapture2D->CaptureScene();
		/*
		UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(MapMaterial, this);
		if (DynMaterial)
		{
			DynMaterial->SetTextureParameterValue("MapTexture", Texture);
			UKismetRenderingLibrary::DrawMaterialToRenderTarget(this, Texture, DynMaterial);
		}
		else {
			return;
		}
		*/
		
	}
}