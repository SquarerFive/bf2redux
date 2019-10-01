// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnrealNetwork.h"
#include "MulticastDelegateBase.h"
#include "BaseObjective.generated.h"

class UReduxPOIComponent;
class UReduxPOIWidget;
class UReduxSpawnableComp;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUpdate);

UENUM(BlueprintType)
enum class EObjectiveType : uint8
{
	TeamSpawn,
	Flag,
	Bomb,
	Other
};

UCLASS()
class REDUXPROJECT_API ABaseObjective : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseObjective();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		UReduxPOIComponent* POIComp;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Replicated)
		UReduxSpawnableComp* SpawnComp;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Category = "Redux Project|Objective")
		int32 Team;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Category = "Redux Project|Objective")
		int32 DominatingTeam;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Category = "Redux Project|Objective")
		float Alpha;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
		FString ObjectiveName;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Category = "Redux Project|Objective|Config")
		bool CanSpawnOn = true;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Category = "Redux Project|Objective|Config")
		bool CanBeCaptured = true;

	UFUNCTION(BlueprintCallable,CallInEditor, Category = "Redux Project|Objective")
		void RunInitialisation();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project|Objective")
		TSubclassOf<UReduxPOIWidget> POIWidget;
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FOnUpdate OnUpdateDelegate;
	UFUNCTION(BlueprintCallable, NetMulticast, UnReliable)
		void MulticastBroadcastUpdate();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Category = "Redux Project|Objective|Config")
		EObjectiveType ObjectiveType = EObjectiveType::Flag;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project|Objective|Config")
		bool bLockObjectiveName=false;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Server, WithValidation, Reliable, Category = "")
		virtual void UpdateObjectiveName();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
private:
	UWorld* World;
};
