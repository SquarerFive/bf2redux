// (C) Aiden Soedjarwo. 2019. Redux Project.


#include "ReduxController.h"
#include "Game/ReduxWorldData.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Engine.h"
#include "Engine/World.h"
#include "Player/ReduxPlayerState.h"
#include "Components/ReduxSpawnableComp.h"
#include "Static/ReduxLibrary.h"
#include "Kismet/KismetRenderingLibrary.h"



void AReduxController::CreateMinimapTexture(int32 Width, int32 Height)
{
	FVector2D Resolution;
	if (!ReduxWorldData)
		ReduxWorldData = Cast<AReduxWorldData>(GetWorld()->GetWorldSettings());
	LocalMinimapMaterial_Dynamic = UKismetMaterialLibrary::CreateDynamicMaterialInstance(this, LocalMinimapMaterial);
	if (LocalMinimapTexture && LocalMinimapMaterial_Dynamic && LocalMinimapTexture_NoMask)
	{

		delete LocalMinimapMaterial_Dynamic;
		delete LocalMinimapTexture;
		delete LocalMinimapTexture_NoMask;

	}
	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(Resolution);
	}
	LocalMinimapTexture = UKismetRenderingLibrary::CreateRenderTarget2D(this, ((Width == 0) ? Resolution.X : Width), ((Height == 0 ? Resolution.Y : Height)));
	LocalMinimapTexture_NoMask = UKismetRenderingLibrary::CreateRenderTarget2D(this, ((Width == 0) ? Resolution.X : Width), ((Height == 0 ? Resolution.Y : Height)));
	if (ReduxWorldData) {
		ReduxWorldData->RenderMinimap(LocalMinimapTexture, LocalMinimapTexture_NoMask, LocalMinimapMaterial_Dynamic);
	}
	OnMinimapTextureUpdatedDelegate.Broadcast(LocalMinimapMaterial_Dynamic);


}

void AReduxController::SwitchTeams()
{
	SwitchTeams_Internal();
}

void AReduxController::SwitchTeams_Internal_Implementation()
{
	if (GetMyPlayerState())
	{
		if (MyPlayerState->Team == 0)MyPlayerState->Team = 1;
		if (MyPlayerState->Team == 1)MyPlayerState->Team = 2;
		if (MyPlayerState->Team == 2)MyPlayerState->Team = 1;
		//MyPlayerState->SendUpdatesToClients();
		UReduxLibrary::Print(this, FString::FromInt(MyPlayerState->Team));
		CallClientUpdate();
	}
}

bool AReduxController::SwitchTeams_Internal_Validate()
{
	
	return true;
}

AReduxPlayerState* AReduxController::GetMyPlayerState()
{
	if (!MyPlayerState)MyPlayerState = Cast<AReduxPlayerState>(PlayerState);
	return ((MyPlayerState != nullptr) ? MyPlayerState : Cast<AReduxPlayerState>(PlayerState));
}

void AReduxController::SetSpawn(UReduxSpawnableComp* Spawn)
{
	SetSpawn_Internal(Spawn);
}

void AReduxController::SetSpawn_Internal_Implementation(UReduxSpawnableComp* Spawn)
{
	if (GetMyPlayerState())
	{
		//MyPlayerState->SendUpdatesToClients();
		MyPlayerState->SpawnLoc = Spawn;
	}
	CallClientUpdate();
}

bool AReduxController::SetSpawn_Internal_Validate(UReduxSpawnableComp* Spawn)
{
	return true;
}

void AReduxController::CallClientUpdate_Implementation()
{
	OnClientUpdate();
}

void AReduxController::OnClientUpdate_Implementation()
{
	return;
}