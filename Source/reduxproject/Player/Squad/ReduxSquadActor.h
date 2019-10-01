// (C) Aiden Soedjarwo. 2019. Redux Project.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnrealNetwork.h"
#include "GameFramework/Controller.h"
#include "ReduxSquadActor.generated.h"

USTRUCT(BlueprintType)
struct FSquadData
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		APlayerState* SquadLeader;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<APlayerState*> Members;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int32 MaxMembers = 5;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSquadUpdate);

UCLASS()
class REDUXPROJECT_API AReduxSquadActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AReduxSquadActor();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
		FSquadData Squad;

	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void AddMember(AController* NewMember);
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void RemoveMember(AController* NewMember);
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void PromoteMember(AController* NewMember);

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
		FSquadUpdate OnSquadUpdate_Delegate;

	UFUNCTION(BlueprintCallable, NetMulticast, UnReliable)
		void UpdateSquad();

	UPROPERTY(BlueprintReadOnly, Replicated)
		int32 Team;

protected:
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
