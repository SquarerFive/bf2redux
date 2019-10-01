// (C) Aiden Soedjarwo. 2019. Redux Project.


#include "ReduxSquadActor.h"
#include "UnrealNetwork.h"
#include "GameFramework/PlayerState.h"


// Sets default values
AReduxSquadActor::AReduxSquadActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

void AReduxSquadActor::AddMember_Implementation(AController* NewMember)
{
	Squad.Members.Add(NewMember->PlayerState);
	if (!Squad.SquadLeader)
	{
		PromoteMember(NewMember);
	}
	UpdateSquad();
}
bool AReduxSquadActor::AddMember_Validate(AController* NewMember)
{
	if (NewMember->PlayerState && (Squad.Members.Num() < Squad.MaxMembers))
		return true;
	return false;
}

void AReduxSquadActor::RemoveMember_Implementation(AController* NewMember)
{
	Squad.Members.Remove(NewMember->PlayerState);
	UpdateSquad();
}
bool AReduxSquadActor::RemoveMember_Validate(AController* NewMember)
{
	if (NewMember && Squad.Members.Find(NewMember->PlayerState))
		return true;
	return false;
}

void AReduxSquadActor::PromoteMember_Implementation(AController* NewMember)
{
	Squad.SquadLeader = NewMember->PlayerState;
	UpdateSquad();
}
bool AReduxSquadActor::PromoteMember_Validate(AController* NewMember)
{
	if (NewMember->PlayerState)
		return true;
	return false;
}


void AReduxSquadActor::UpdateSquad_Implementation()
{
	OnSquadUpdate_Delegate.Broadcast();
}


void AReduxSquadActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AReduxSquadActor, Squad);
	DOREPLIFETIME(AReduxSquadActor, Team);
}

// Called when the game starts or when spawned
void AReduxSquadActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReduxSquadActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

