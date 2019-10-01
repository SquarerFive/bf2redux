// (C) Aiden Soedjarwo. 2019. Redux Project.


#include "ReduxGameState.h"
#include "EngineUtils.h"
#include "CoreMinimal.h"
#include "UnrealNetwork.h"
#include "Game/BaseObjective.h"


AReduxGameState::AReduxGameState()
{
	bReplicates = true;
	UWorld* World = GetWorld();
	if (World)
	{
		int i = 0;
		for (TActorIterator<ABaseObjective> ObjItr(World); ObjItr; ++ObjItr)
		{
			i++;
			Objectives.Add(*ObjItr);
		}
	}
}

void AReduxGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AReduxGameState, Objectives);
}

void AReduxGameState::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(Objectives.Num()));
}
/* Undocumented from here, code is pretty self explanatory */
void AReduxGameState::AddChatMessage_Implementation(APlayerState* Player, const FString& Message)
{
	if (HasAuthority() && Player && (!Message.IsEmpty()))
	{
		FGameChatData ChatData; ChatData.Owner = Player; ChatData.Message = Message;
		InGameChat.Add(ChatData);
		OnAddChatMessage(ChatData);
	}
}
bool AReduxGameState::AddChatMessage_Validate(APlayerState* Player, const FString& Message)
{
	/*
	if (Player && (!Message.IsEmpty()))
	{
		return true;
	}
	return false*/

	return ((Player && (!Message.IsEmpty())) ? true : false);
}
void AReduxGameState::OnAddChatMessage_Implementation(FGameChatData ChatData)
{
	ChatMessageSentDelegate.Broadcast(ChatData);
}