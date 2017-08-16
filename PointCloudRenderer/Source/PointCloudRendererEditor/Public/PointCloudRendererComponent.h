// (c) 2017 by Valentin Kraft, http://www.valentinkraft.de

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PointCloudRendererComponent.generated.h"


UCLASS( ClassGroup=Rendering, meta=(BlueprintSpawnableComponent), hideCategories = (Object, LOD, Physics, Collision))
class POINTCLOUDRENDEREREDITOR_API UPointCloudRendererComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPointCloudRendererComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PointCloudRenderer")
	FString filePath;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
