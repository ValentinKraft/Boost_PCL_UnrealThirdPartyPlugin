// (c) 2017 by Valentin Kraft, http://www.valentinkraft.de

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "IPointCloudRenderer.h"
#include "GenericPlatform.h"
#include "GenericPlatformProcess.h"

THIRD_PARTY_INCLUDES_START
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <boost/shared_ptr.hpp>
THIRD_PARTY_INCLUDES_END

DECLARE_LOG_CATEGORY_EXTERN(PointCloudRenderer, Log, All);
DEFINE_LOG_CATEGORY(PointCloudRenderer);

class FPointCloudRenderer : public IPointCloudRenderer
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	int LoadPCDFile();

private:
	pcl::PointCloud<pcl::PointXYZ> cloud;
};

IMPLEMENT_MODULE(FPointCloudRenderer, PointCloudRenderer)


void FPointCloudRenderer::StartupModule()
{
	UE_LOG(PointCloudRenderer, Log, TEXT("################################### \n"));
	UE_LOG(PointCloudRenderer, Log, TEXT("## Starting Point Cloud Renderer... \n"));
	UE_LOG(PointCloudRenderer, Log, TEXT("################################### \n"));

	FPointCloudRenderer::LoadPCDFile();
}


int FPointCloudRenderer::LoadPCDFile() {

	if (pcl::io::loadPCDFile<pcl::PointXYZ>("C:\\bunny.pcd", cloud) == -1)		//Dummy function call - please change
	{
		UE_LOG(PointCloudRenderer, Error, TEXT("Couldn't read pcd file. Please change dummy function in PointCloudRenderer.cpp!\n"));

		return (-1);
	}

	auto w = FString::FromInt(cloud.width * cloud.height);
	UE_LOG(PointCloudRenderer, Log, TEXT("Succesfully loaded %s data points."),*w);

	return (1);
}


void FPointCloudRenderer::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}
