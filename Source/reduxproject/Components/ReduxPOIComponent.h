// (C) Aiden Soedjarwo. 2019. Redux Project.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Minimap/ReduxPOIWidget.h"
#include "ReduxPOIComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class REDUXPROJECT_API UReduxPOIComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UReduxPOIComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Redux Project|Minimap", meta=(ExposeOnSpawn = "true"))
		TSubclassOf<UReduxPOIWidget> POIWidget;
	
	
};
