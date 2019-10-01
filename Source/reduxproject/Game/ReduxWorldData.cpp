// (C) Aiden Soedjarwo. 2019. Redux Project.


#include "ReduxWorldData.h"
#include "Engine/World.h"
#include "Engine/Classes/Materials/Material.h"
#include "World/ReduxPlayArea.h"
#include "Engine/Classes/Materials/MaterialInstanceDynamic.h"
void AReduxWorldData::CreateMinimap()
{
	UWorld* World = GetWorld();
	FVector Location(0.f, 0.f, 5000.f);
	FRotator Rotation(-90.f,0.f,0.f);
	FActorSpawnParameters SpawnInfo;
	if (World)
	{
		TArray<AReduxPlayArea*> PlayAreas = UReduxLibrary::GetPlayAreas(this);
		AMinimapCapture * MapCapture = World->SpawnActor<AMinimapCapture>(CameraTransform.GetLocation(),FRotator(CameraTransform.GetRotation()), SpawnInfo);
		if (MapCapture && MinimapTexture && MinimapTexture_UnMasked)
		{
			if (PlayAreas.Num() > 0)
			{
				for (AReduxPlayArea* PlayAreaVolume : PlayAreas)
				{
					PlayAreaVolume->SetActorHiddenInGame(false);
				}
			}
			MapCapture->CaptureMinimap(MinimapTexture, MinimapWidth, MapCaptureType, MinimapMaterial);
			if (PlayAreas.Num() > 0)
			{
				for (AReduxPlayArea * PlayAreaVolume : PlayAreas)
				{
					PlayAreaVolume->SetActorHiddenInGame(true);
				}
			}
			MapCapture->CaptureMinimap(MinimapTexture_UnMasked, MinimapWidth, MapCaptureType, MinimapMaterial);
			if (PlayAreas.Num() > 0)
			{
				for (AReduxPlayArea* PlayAreaVolume : PlayAreas)
				{
					PlayAreaVolume->SetActorHiddenInGame(false);
				}
			}
		}

		if (MapCapture) { MapCapture->Destroy(); }
		World = NULL;
	}
}


float AReduxWorldData::GetMinimapWidth()
{
	return MinimapWidth;
}

void AReduxWorldData::RenderMinimap(UTextureRenderTarget2D* RenderTarget, UTextureRenderTarget2D* RenderTarget_NoMask, UMaterialInstanceDynamic * Material)
{
	UWorld* World = GetWorld();
	FActorSpawnParameters SpawnInfo;
	TArray<AReduxPlayArea*> PlayAreas = UReduxLibrary::GetPlayAreas(this);
	if (World)
	{

		AMinimapCapture* MapCapture = World->SpawnActor<AMinimapCapture>(CameraTransform.GetLocation(), FRotator(CameraTransform.GetRotation()), SpawnInfo);
		if (MapCapture && RenderTarget && RenderTarget_NoMask)
		{
			if (PlayAreas.Num() > 0)
			{
				for (AReduxPlayArea* PlayAreaVolume : PlayAreas)
				{
					PlayAreaVolume->SetActorHiddenInGame(false);
				}
			}
			MapCapture->CaptureMinimap(RenderTarget, MinimapWidth, MapCaptureType, NULL);
			if (PlayAreas.Num() > 0)
			{
				for (AReduxPlayArea* PlayAreaVolume : PlayAreas)
				{
					PlayAreaVolume->SetActorHiddenInGame(true);
				}
			}
			MapCapture->CaptureMinimap(RenderTarget_NoMask, MinimapWidth, MapCaptureType, NULL);
			if (PlayAreas.Num() > 0)
			{
				for (AReduxPlayArea* PlayAreaVolume : PlayAreas)
				{
					PlayAreaVolume->SetActorHiddenInGame(false);
				}
			}
		}
		Material->SetTextureParameterValue("MapTexture", RenderTarget);
		Material->SetTextureParameterValue("MapTexture_UnMasked", RenderTarget_NoMask);
		if (MapCapture) { MapCapture->Destroy(); }
		World = NULL;
	}
}

void AReduxWorldData::AutoAdjustToActor()
{
	if (AdjustmentActor)
	{
		FVector Location;
		FVector Bounds;
		AdjustmentActor->GetActorBounds(true, Location, Bounds);

		CameraTransform.SetLocation(Location);
		MinimapWidth = (Bounds.X*2);
	}
}