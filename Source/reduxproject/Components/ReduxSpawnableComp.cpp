// (C) Aiden Soedjarwo. 2019. Redux Project.


#include "ReduxSpawnableComp.h"
#include "Static/ReduxLibrary.h"
// Sets default values for this component's properties
UReduxSpawnableComp::UReduxSpawnableComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UReduxSpawnableComp::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UReduxSpawnableComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

