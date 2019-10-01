// (C) Aiden Soedjarwo. 2019. Redux Project.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ReduxSpawnableComp.generated.h"

class UReduxPOIWidget;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class REDUXPROJECT_API UReduxSpawnableComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UReduxSpawnableComp();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int32 Team = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bUseWidget;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<UReduxPOIWidget> WidgetClass;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UTexture2D* Texture;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString Name;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
