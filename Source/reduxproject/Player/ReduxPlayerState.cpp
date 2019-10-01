// (C) Aiden Soedjarwo. 2019. Redux Project.


#include "ReduxPlayerState.h"
#include "UnrealNetwork.h"
#include "Components/ReduxSpawnableComp.h"


void AReduxPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AReduxPlayerState, Team);
	DOREPLIFETIME(AReduxPlayerState, SpawnLoc);
}



void AReduxPlayerState::ChangeTeam_Implementation(int32 NewTeam)
{
	if (HasAuthority())
	{
		Team = NewTeam;
		SendUpdatesToClients();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(NewTeam));
		// OnPlayerBasicUpdate.Broadcast();
	}
}

bool AReduxPlayerState::ChangeTeam_Validate(int32 NewTeam)
{
	return true;
}

void AReduxPlayerState::SetSpawn_Implementation(UReduxSpawnableComp* SpawnActorComp)
{
	SpawnLoc = SpawnActorComp;
	SendUpdatesToClients();
	// OnPlayerBasicUpdate.Broadcast();
}

bool AReduxPlayerState::SetSpawn_Validate(UReduxSpawnableComp* SpawnActorComp)
{
	if (SpawnActorComp->IsValidLowLevel())
	{
		if (SpawnActorComp->Team == Team)
		{
			return true;
		}
	}
	return false;
}

void AReduxPlayerState::SendUpdatesToClients_Implementation()
{
	OnPlayerBasicUpdate.Broadcast();
}