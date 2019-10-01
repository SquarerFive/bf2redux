// (C) Aiden Soedjarwo. 2019. Redux Project.


#include "ReduxGameMode.h"
#include "Game/ReduxGameState.h"
#include "Player/ReduxPlayerState.h"
void AReduxGameMode::StartConquest(EGameSize GameSize, int32 Tickets)
{
}
void AReduxGameMode::Autobalance																							()
																															{
	TArray<APlayerState*> PlayerStateArray																					;
	AReduxGameState* ReduxGameStateRef = UReduxLibrary::GetReduxGameState													(this);
	int32 Temp; int32 Temp2																									;
	if (ReduxGameStateRef->IsValidLowLevel())																				{
		PlayerStateArray = ReduxGameStateRef->PlayerArray																	;
		int32 TotalPlayers = PlayerStateArray.Num																			();
		for (int i = 1; i < NumTeams + 1; i++)
																															{
			Temp=0																											;
			for (APlayerState* Player : PlayerStateArray)
																															{
				if (Cast<AReduxPlayerState>(Player)->Team == i)
																															{
					Temp++																									;
																															}
				
																															}
			if ((Temp > int32(TotalPlayers/NumTeams) || (Temp < int32(TotalPlayers/NumTeams))))
																															{
				if (i + 1 <= NumTeams)
																															{
					Temp2=0																									;
					for (APlayerState* Player : PlayerStateArray)
																															{
						if (Cast<AReduxPlayerState>(Player)->Team == i + 1)
																															{
							Temp2++																							;
																															}
						if (Temp2 < Temp)
																															{
							Cast<AReduxPlayerState>(Player)->ChangeTeam(i + 1)												;
																															}
																															}
																															}
				if (i - 1 >= NumTeams)
																															{
					Temp2=0																									;
					for (APlayerState* Player : PlayerStateArray)
																															{
						if (Cast<AReduxPlayerState>(Player)->Team == i - 1)
																															{
							Temp2++																							;
																															}
						if (Temp2 < Temp)																					{
							Cast<AReduxPlayerState>(Player)->ChangeTeam(i - 1)												;
																															}
																															}
																															}
																															}
																															}
																															} /* Temporary Function */
																															} void AReduxGameMode::GetPlayersInTeams() { return; }

