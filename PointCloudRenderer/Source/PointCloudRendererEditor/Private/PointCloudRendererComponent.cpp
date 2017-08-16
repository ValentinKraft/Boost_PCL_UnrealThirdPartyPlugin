// (c) 2017 by Valentin Kraft, http://www.valentinkraft.de

#include "PointCloudRendererComponent.h"
#include "IPointCloudRenderer.h"


// Sets default values for this component's properties
UPointCloudRendererComponent::UPointCloudRendererComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPointCloudRendererComponent::BeginPlay()
{
	Super::BeginPlay();

	// Connection to the PointCloudRenderer module -> call load function
	if (IPointCloudRenderer::IsAvailable())
		int x = IPointCloudRenderer::Get().LoadPCDFile();
}


// Called every frame
void UPointCloudRendererComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

