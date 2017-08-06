// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using System.IO;
using System;

namespace UnrealBuildTool.Rules
{
    public class PCL : ModuleRules
    {
        private string ModulePath
        {
            get { return ModuleDirectory; }
        }

        private string BinariesPath
        {
            get { return Path.GetFullPath(Path.Combine(ModulePath, "../Binaries/")); }
        }

        public PCL(ReadOnlyTargetRules Target) : base(Target)
        {
            // Tell Unreal that this Module only imports Third-Party-Assets
            Type = ModuleType.External;

            LoadPCL(Target);
        }

        public bool LoadPCL(ReadOnlyTargetRules Target)
        {
            bool isLibrarySupported = false;
            bool bDebug = (Target.Configuration == UnrealTargetConfiguration.Debug && BuildConfiguration.bDebugBuildsActuallyUseDebugCRT);

            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                isLibrarySupported = true;

                //string PlatformString = (Target.Platform == UnrealTargetPlatform.Win64) ? "x64" : "x86";

                // Explicitly name the used libraries
                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "Boost/lib/libboost_chrono-vc141-mt-1_64.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "Boost/lib/libboost_date_time-vc141-mt-1_64.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "Boost/lib/libboost_filesystem-vc141-mt-1_64.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "Boost/lib/libboost_iostreams-vc141-mt-1_64.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "Boost/lib/libboost_system-vc141-mt-1_64.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "Boost/lib/libboost_thread-vc141-mt-1_64.lib"));

                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "PCL_181/lib/pcl_common_release.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "PCL_181/lib/pcl_io_release.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "PCL_181/lib/pcl_io_ply_release.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "PCL_181/lib/pcl_octree_release.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "PCL_181/lib/pcl_ml_release.lib"));
                //PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "PCL_181/lib/pcl_visualization_release.lib"));
            }

            if (isLibrarySupported)
            {
                PublicIncludePaths.Add(Path.Combine(ModulePath, "Eigen/eigen3"));
                PublicIncludePaths.Add(Path.Combine(ModulePath, "Boost/include/boost-1_64"));
                PublicIncludePaths.Add(Path.Combine(ModulePath, "PCL_181/include/pcl-1.8"));
                //PublicIncludePaths.Add(Path.Combine(ModulePath, "FLANN/include"));
                //PublicIncludePaths.Add(Path.Combine(ModulePath, "VTK/include/vtk-8.0"));

                // Not sure if needed
                Definitions.Add("_CRT_SECURE_NO_WARNINGS=1");
                Definitions.Add("BOOST_DISABLE_ABI_HEADERS=1");

                // Needed configurations in order to run Boost
                bUseRTTI = true;
                bEnableExceptions = true;
                //bEnableUndefinedIdentifierWarnings = false;
            }

            Definitions.Add(string.Format("WITH_PCL_BINDING={0}", isLibrarySupported ? 1 : 0));
            Definitions.Add(string.Format("WITH_BOOST_BINDING={0}", isLibrarySupported ? 1 : 0));

            return isLibrarySupported;
        }
    }
}
