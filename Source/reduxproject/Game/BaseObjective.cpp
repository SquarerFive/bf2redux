/*
~~~~~ Redux Project ~~~~~
 A Battlefield 2 Remake.
  Aiden S. 2019
~~~~~~~~~~~~~~~~~~~~~~~~~
*/


#include "BaseObjective.h"
#include "EngineUtils.h"
#include "Static/ReduxLibrary.h"
#include "UnrealNetwork.h"
#include "Components/ReduxPOIComponent.h"
#include "Components/ReduxSpawnableComp.h"
#include "Minimap/ReduxPOIWidget.h"
// Sets default values
ABaseObjective::ABaseObjective()
{
 	// Enabled tick because it may be used later.........
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	World = GetWorld();
	RunInitialisation();
	POIComp = CreateDefaultSubobject<UReduxPOIComponent>(TEXT("POIComponent"));
	if (POIComp)
	{
		POIComp->POIWidget = POIWidget;
	}
	if (CanSpawnOn)
		SpawnComp = CreateDefaultSubobject<UReduxSpawnableComp>(TEXT("SpawnComponent"));
	if (SpawnComp)
	{
		SpawnComp->Team = Team;
		SpawnComp->SetNetAddressable();
		SpawnComp->SetIsReplicated(true); 
	}
}

// Called when the game starts or when spawned
void ABaseObjective::BeginPlay()
{
	Super::BeginPlay();
	if (POIComp)
	{
		POIComp->POIWidget = POIWidget;
	}
	if (SpawnComp)
	{
		switch (ObjectiveType)
		{
			case (EObjectiveType::TeamSpawn):
				SpawnComp->Name = "Team Spawn";
				break;
			case (EObjectiveType::Flag):
				SpawnComp->Name = ObjectiveName;
				break;
		}
	}
	
}

void ABaseObjective::UpdateObjectiveName_Implementation()
{
	if (HasAuthority())
	{
		UWorld* World = GetWorld();
		if (World)
		{
			// ~~ Do something! ~~ //
			RunInitialisation();
		}
	}
}
bool ABaseObjective::UpdateObjectiveName_Validate()
{
	return true;
}

// Called every frame
void ABaseObjective::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseObjective::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABaseObjective, Team);
	DOREPLIFETIME(ABaseObjective, DominatingTeam);
	DOREPLIFETIME(ABaseObjective, Alpha);
	DOREPLIFETIME(ABaseObjective, ObjectiveName);
	DOREPLIFETIME(ABaseObjective, CanBeCaptured);
	DOREPLIFETIME(ABaseObjective, ObjectiveType);
	DOREPLIFETIME(ABaseObjective, CanSpawnOn);
	DOREPLIFETIME(ABaseObjective, SpawnComp);
}


// Absolute Headache.
void ABaseObjective::RunInitialisation()
{
	if (World && !bLockObjectiveName)
	{
		int i = 0;
		for (TActorIterator<ABaseObjective> ObjItr(World); ObjItr; ++ObjItr)
		{
			if ((ObjItr->CanBeCaptured))
			{
				i++;
				if (*ObjItr == this)
				{
					ObjectiveName = UReduxLibrary::GetPhoneticAlphabet()[i - 1]; // shit but works.
				}
			}
		}
	}
}

void ABaseObjective::MulticastBroadcastUpdate_Implementation()
{
	if (1==1)
	{
		OnUpdateDelegate.Broadcast();
	}
}
