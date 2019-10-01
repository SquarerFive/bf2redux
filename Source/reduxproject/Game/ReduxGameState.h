// (C) Aiden Soedjarwo. 2019. Redux Project.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ReduxGameState.generated.h"

/**
 * 
 */
class ABaseObjective;
USTRUCT(BlueprintType)
struct FGameChatData {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project|Gamestate")
		FString Message;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project|Gamestate")
		APlayerState* Owner;
	FGameChatData()
	{
		Message = "";
		Owner = nullptr;
	}
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChatMessageSent, FGameChatData, ChatData);

UCLASS()
class REDUXPROJECT_API AReduxGameState : public AGameStateBase
{
	GENERATED_BODY()

	AReduxGameState();
public:
	UPROPERTY(BlueprintReadOnly, Replicated, Category = "Redux Project|Gamestate")
		TArray<ABaseObjective*> Objectives;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Redux Project|Gamestate")
		TArray<FGameChatData> InGameChat;
	UFUNCTION(BlueprintCallable, Server, WithValidation, UnReliable, Category = "Redux Project|Gamestate")
		void AddChatMessage(APlayerState* Player, const FString& Message);
	UFUNCTION(NetMulticast,UnReliable, Category = "Redux Project|Gamestate")
		void OnAddChatMessage(FGameChatData ChatData);
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Redux Project|Gamestate")
		FOnChatMessageSent ChatMessageSentDelegate;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void BeginPlay() override;
};
