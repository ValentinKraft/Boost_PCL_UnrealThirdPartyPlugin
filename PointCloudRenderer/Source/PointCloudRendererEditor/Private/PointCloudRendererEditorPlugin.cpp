// (c) 2017 by Valentin Kraft, http://www.valentinkraft.de

#include "CoreMinimal.h"
#include "UObject/Class.h"
#include "PropertyEditorModule.h"
#include "Modules/ModuleManager.h"
#include "IPointCloudRendererEditorPlugin.h"
#include "AssetData.h"
#include "AssetRegistryModule.h"
#include "Engine/Blueprint.h"

class FPointCloudRendererEditorPlugin : public IPointCloudRendererEditorPlugin
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override
	{
		//FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
		//PropertyModule.RegisterCustomClassLayout("WheeledVehicleMovementComponent4W", FOnGetDetailCustomizationInstance::CreateStatic(&FWheeledVehicleMovementComponent4WDetails::MakeInstance));
		//PropertyModule.RegisterCustomPropertyTypeLayout("VehicleTransmissionData", FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FVehicleTransmissionDataCustomization::MakeInstance));
		//PropertyModule.NotifyCustomizationModuleChanged();
	}


	virtual void ShutdownModule() override
	{
		//FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
		//PropertyModule.UnregisterCustomClassLayout("WheeledVehicleMovementComponent4W");
		//PropertyModule.UnregisterCustomPropertyTypeLayout("VehicleTransmissionData");
		//PropertyModule.NotifyCustomizationModuleChanged();
	}
};

IMPLEMENT_MODULE(FPointCloudRendererEditorPlugin, PointCloudRendererEditor)
