// ReduxProject
// Aiden Soedjarwo. 2019
// SquarerFive.


#include "ReduxLibrary.h"
#include "Game/ReduxGameState.h"
#include "Player/ReduxPlayerState.h"
#include "Engine/World.h"
#include "Engine.h"
#include "Game/ReduxWorldData.h"
#include "EngineUtils.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Core/ReduxGameInstance.h"
#include "World/ReduxPlayArea.h"
#include "Components/ReduxSpawnableComp.h"

bool UReduxLibrary::IsFriendly(int32 MyTeam, int32 TheirTeam)
{
	return (MyTeam == TheirTeam ? true : false);
}

bool UReduxLibrary::IsEnemy(UObject* WorldContextObject, APlayerState* Me, int32 OtherTeam)
{
	if(!(WorldContextObject && Me))
		return false;
	return ((Cast<AReduxPlayerState>(Me)->Team != OtherTeam) ? true : false);
}

// Serialised Enums won't work so it will be stored in a string.
TArray<FString> UReduxLibrary::GetPhoneticAlphabet()
{
	TArray<FString> Alphabet = { "Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima",
			"Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "X-Ray", "Yankee", "Zulu"
	};
	return Alphabet;
}

AReduxGameState* UReduxLibrary::GetReduxGameState(UObject* WorldContextObject)
{
	if (WorldContextObject)
	{
		AReduxGameState * ARGameState = Cast<AReduxGameState>(WorldContextObject->GetWorld()->GetGameState());
		return ARGameState;
	}
	return nullptr;
}
	

AReduxWorldData* UReduxLibrary::GetReduxWorldSettings(UObject* WorldContextObject)
{
	if (WorldContextObject)
	{
		return Cast<AReduxWorldData>(WorldContextObject->GetWorld()->GetWorldSettings());
	}
	return nullptr;
}

AReduxWorldData* UReduxLibrary::GetReduxWorldSettingsPure(UObject* WorldContextObject)
{
	if (WorldContextObject)
	{
		return Cast<AReduxWorldData>(WorldContextObject->GetWorld()->GetWorldSettings());
	}
	return nullptr;
}

float UReduxLibrary::GetMinimapWidth(UWorld* WorldContextObject)
{
	AReduxWorldData* WorldData = GetReduxWorldSettings(WorldContextObject);
	if (WorldData)
	{
		return WorldData->GetMinimapWidth();
	}
	return 0.0f;
}

TArray<AReduxPlayArea*> UReduxLibrary::GetPlayAreas(UObject* WorldContextObject)
{
	if (!WorldContextObject)
		return TArray<AReduxPlayArea*>();
	TArray <AReduxPlayArea*> PlayAreaArray;
	for (TActorIterator<AReduxPlayArea> ActorItr(WorldContextObject->GetWorld()); ActorItr; ++ActorItr)
	{
		PlayAreaArray.Add(*ActorItr);
	}
	return PlayAreaArray;
}

TArray<AActor*> UReduxLibrary::GetAllActorsOfClassWithComponent(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, TSubclassOf<UActorComponent> ActorComponent)
{
	TArray<AActor*> ActorsWithComponents;
	if (!WorldContextObject) return TArray<AActor*>();
	for (TActorIterator<AActor> ActorItr(WorldContextObject->GetWorld()); ActorItr; ++ActorItr) {
		if (ActorItr->GetComponentByClass(ActorComponent) && ActorItr->StaticClass() == ActorClass)
		{
			ActorsWithComponents.Add(*ActorItr);
		}
	}
	return ActorsWithComponents;
}

FGameUISettings UReduxLibrary::GetGameUISettings(UObject* WorldContextObject)
{
	UReduxGameInstance* MyGameInstance;
	if (GEngine->GetWorld() != nullptr)
	{
		if (GEngine->GetWorld()->GetGameInstance())
		{
			MyGameInstance = Cast<UReduxGameInstance>(GEngine->GetWorld()->GetGameInstance());
			if (MyGameInstance)
			{
				return MyGameInstance->GameUISettings;
			}
			
		}
	}
	if (WorldContextObject)
	{
		if (WorldContextObject->GetWorld()->GetGameInstance())
		{
		    MyGameInstance = Cast<UReduxGameInstance>(WorldContextObject->GetWorld()->GetGameInstance());
			if (MyGameInstance)
				return MyGameInstance->GameUISettings;
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Unable to get GameInstance"));
	return FGameUISettings();
}

TArray<AActor*> UReduxLibrary::GetActorsICanSpawnOn(UObject* WorldContextObject, int32 Team)
{
	if (!(WorldContextObject))
	return TArray<AActor*>();

	TArray<AActor*> UnfilteredComponentArray = GetAllActorsOfClassWithComponent(WorldContextObject, AActor::StaticClass(), UReduxSpawnableComp::StaticClass());
	TArray<AActor*> FilteredComponentArray;
	UReduxSpawnableComp* SpawnComp;
	for (AActor* Actor : UnfilteredComponentArray)
	{
		SpawnComp = Cast<UReduxSpawnableComp>(Actor->GetComponentByClass(UReduxSpawnableComp::StaticClass()));
		if (SpawnComp)
		{
			if (SpawnComp->Team == Team)
			FilteredComponentArray.Add(Actor);
		}
	}
	return FilteredComponentArray;

}

void UReduxLibrary::Print(UObject * WorldContextObject, FString String, FLinearColor Colour, FString Prefix, FString Source)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Purple, String);
	UReduxGameInstance* __ReduxGameInstance = GetReduxGameInstance(WorldContextObject);
	// if (__ReduxGameInstance)__ReduxGameInstance->DebugLogs.Add(FLogUIType(String, Colour, Prefix, Source));
}

UReduxGameInstance* UReduxLibrary::GetReduxGameInstance(UObject* WorldContextObject)
{
	UWorld * World = WorldContextObject->GetWorld();
	if (World)
	{
		UReduxGameInstance* GameInstance = Cast<UReduxGameInstance>(World->GetGameInstance());
		if (GameInstance)
		{
			return GameInstance;
		}
	}
	return nullptr;
}