// (C) Aiden Soedjarwo. 2019. Redux Project.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReduxPlayArea.generated.h"

UCLASS()
class REDUXPROJECT_API AReduxPlayArea : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AReduxPlayArea();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UStaticMesh* Mesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UMaterialInterface* Material;
	UPROPERTY(BlueprintReadWrite)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FTransform MeshTransform;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int32 Index = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bActivated = true;

	UFUNCTION(BlueprintCallable, CallInEditor)
		void Refresh();
};
