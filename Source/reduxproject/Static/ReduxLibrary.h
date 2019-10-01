// ReduxProject
// Aiden Soedjarwo. 2019
// SquarerFive.

/*
License Notice:

MIT, provided AS IS with no warranties.
You may study, modify or use this code. 
*/
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/Core/Public/Containers/StaticArray.h"
#include "ReduxLibrary.generated.h"

/**
 * 
 */
class AReduxGameState;
class AReduxWorldData;
class AReduxPlayArea;
class UReduxGameInstance;

UENUM(BlueprintType)
enum class EPhoneticAlphabet : uint8
{
	Alpha,
	Bravo,
	Charlie,
	Delta,
	Echo,
	Foxtrot,
	Golf,
	Hotel,
	India,
	Juliett,
	Kilo,
	Lima,
	Mike,
	November,
	Oscar,
	Papa,
	Quebec,
	Romeo,
	Sierra,
	Tango,
	Uniform,
	Victor,
	Whiskey,
	XRay,
	Yankee,
	Zulu
};
UENUM(BlueprintType)
enum class EGameSize : uint8
{
	Small,
	Medium,
	Large
};
UENUM(BlueprintType)
enum class EGamePresets : uint8
{
	Normal,
	Hardcore,
	Custom,
	
	/* Maybe? lol */
	Cooperative,
	Zombies
};
UENUM(BlueprintType)
enum class EGameMode : uint8
{
	Conquest,
	Rush,
	TeamDeathmatch,
	Domination,
	Defuse,
	Obliteration,
	SquadObliteration,
	SquadDomination,
	SquadDeathmatch,
	FreeForAll
};
USTRUCT(BlueprintType)
struct FTeamData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int32 Team;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UTexture2D* Flag;
};
														// ░░░░░░░░░░░░░░░░░░░░░░░░░░░
USTRUCT(BlueprintType)									// ░░░░░░░░░░░░░▄███▄▄▄░░░░░░░
struct FGameUISettings									// ░░░░░░░░░▄▄▄██▀▀▀▀███▄░░░░░
{														// ░░░░░░░▄▀▀░░░░░░░░░░░▀█░░░░
	GENERATED_BODY()									// ░░░░▄▄▀░░░░░░░░░░░░░░░▀█░░░
														// ░░░█░░░░░▀▄░░▄▀░░░░░░░░█░░░
	UPROPERTY(BlueprintReadWrite, EditAnywhere)			// ░░░▐██▄░░▀▄▀▀▄▀░░▄██▀░▐▌░░░
		FLinearColor FriendlyColour;					// ░░░█▀█░▀░░░▀▀░░░▀░█▀░░▐▌░░░
	UPROPERTY(BlueprintReadWrite, EditAnywhere)			// ░░░█░░▀▐░░░░░░░░▌▀░░░░░█░░░
		FLinearColor EnemyColour;						// ░░░█░░░░░░░░░░░░░░░░░░░█░░░
	UPROPERTY(BlueprintReadWrite, EditAnywhere)			// ░░░░█░░▀▄░░░░▄▀░░░░░░░░█░░░
		FLinearColor SquadColour;						// ░░░░█░░░░░░░░░░░▄▄░░░░█░░░░
	UPROPERTY(BlueprintReadWrite, EditAnywhere)			// ░░░░░█▀██▀▀▀▀██▀░░░░░░█░░░░
		FLinearColor NeutralColour;						// ░░░░░█░░▀████▀░░░░░░░█░░░░░
};														// ░░░░░░█░░░░░░░░░░░░▄█░░░░░░
														// ░░░░░░░██░░░░░█▄▄▀▀░█░░░░░░
USTRUCT(BlueprintType)									// ░░░░░░░░▀▀█▀▀▀▀░░░░░░█░░░░░
struct FLogUIType										// ░░░░░░░░░█░░░░░░░░░░░░█░░░░
{														//			yeeeeeee
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FLinearColor Colour;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString Prefix;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString Source;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString Message;
	FLogUIType()
	{
		Colour = FColor::Red;
		Prefix = "LOG";
		Source = "Redux";
		Message = "Hello World";
	}
};


UCLASS()
class REDUXPROJECT_API UReduxLibrary : public UBlueprintFunctionLibrary
	{
		GENERATED_BODY()
	public:

		UFUNCTION(BlueprintPure, Category = "Redux Project")
			static bool IsFriendly(int32 MyTeam, int32 TheirTeam);

		UFUNCTION(BlueprintPure, Category = "Redux Project", meta = (WorldContext = "WorldContextObject"))
			static bool IsEnemy(UObject * WorldContextObject, APlayerState * Me, int32 OtherTeam);

		/* Removed * 
			UPROPERTY(BlueprintReadOnly, EditAnywhere)
				const static TStaticArray<FString, 26> PhoneticAlphabetArray = {
					"Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima",
						"Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "X-Ray", "Yankee", "Zulu"
				}; */

		UFUNCTION(BlueprintPure, Category = "Redux Project")
			static TArray<FString> GetPhoneticAlphabet();

		UFUNCTION(BlueprintPure, Category = "Redux Project", meta = (WorldContext = "WorldContextObject"))
			static AReduxGameState * GetReduxGameState(UObject * WorldContextObject);

		UFUNCTION(BlueprintPure, Category = "Redux Project", meta = (WorldContext = "WorldContextObject"))
			static AReduxWorldData * GetReduxWorldSettingsPure(UObject * WorldContextObject);

		UFUNCTION(BlueprintCallable, Category = "Redux Project")
			static AReduxWorldData* GetReduxWorldSettings(UObject* WorldContextObject);

		UFUNCTION(BlueprintPure, Category = "Redux Project", meta = (WorldContext = "WorldContextObject"))
			static float GetMinimapWidth(UWorld * WorldContextObject);

		UFUNCTION(BlueprintCallable, Category = "Redux Project|World", meta = (WorldContext = "WorldContextObject"))
			static TArray<AReduxPlayArea*> GetPlayAreas(UObject * WorldContextObject);

		UFUNCTION(BlueprintCallable, Category = "Redux Project|World")
			static TArray<AActor*> GetAllActorsOfClassWithComponent(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, TSubclassOf<UActorComponent> ActorComponent);

		UFUNCTION(BlueprintCallable, Category = "Redux Project", meta = (WorldContext = "WorldContextObject"))
			static FGameUISettings GetGameUISettings(UObject * WorldContextObject);

		UFUNCTION(BlueprintCallable, Category = "Redux Project", meta = (WorldContext = "WorldContextObject"))
			static TArray<AActor*> GetActorsICanSpawnOn(UObject * WorldContextObject, int32 Team);

		UFUNCTION(BlueprintCallable, Category = "Redux Project", meta = (WorldContext = "WorldContextObject"))
			static void Print(UObject * WorldContextObject, FString String, FLinearColor Colour = FLinearColor(255,0,0), FString Prefix=TEXT("Hello World"), FString Source=TEXT("ReduxLibrary"));

		UFUNCTION(BlueprintCallable, Category = "Redux Project", meta = (WorldContext = "WorldContextObject"))
			static UReduxGameInstance* GetReduxGameInstance(UObject* WorldContextObject);
};
