# Boost / PCL Unreal Third-Party Plugin
A template for a Unreal Engine plugin including a C++ Third Party library (on the example of the Point Cloud Library and Boost).

* PCL version: 1.8.1, 64bit
* Boost version: 1.64, 64bit
* Tested with UE Version: 4.18

For the corresponding tutorial please visit:

http://www.valentinkraft.de/including-the-point-cloud-library-into-unreal-tutorial/

# Installation
Please put this in your Engine/project plugin folder and activate the Plugin in Unreal (If you want to use it as an Engine plugin, you _have to include the plugin into a project once_, so Unreal can compile your plugin before you can put it in your engine's plugin folder). When the engine asks you for recompiling, do it.

# Usage
If you want to use this as a starting point for your own plugin / other third party libraries please insert your Third-Party libraries in /Source/ThirdParty/ and change the PCL.Build.cs accordingly (details see tutorial, link above).

If you only want to use PCL/Boost functions in your project, you have to add the PCL/Boost module to your project's Build.cs file:
```c#
PublicDependencyModuleNames.Add("PCL");
```
  Depending on your system you **might** also have to enable RTTI and Exceptions as well (try without first):
  ```c#
  bUseRTTI = true;
  bEnableExceptions = true;
  ```
Now you can include your external libraries in your classes like this:
```c++
THIRD_PARTY_INCLUDES_START
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <boost/shared_ptr.hpp>
THIRD_PARTY_INCLUDES_END
```
And call your third-party functions like this, for example (please see/change PointCloudRenderer.cpp):
```c++
pcl::io::loadPCDFile<pcl::PointXYZ>("C:\\bunny.pcd", cloud);
```

**Please note:**
* This Plugin doesn't provide a point cloud renderer. It merely includes the point cloud library (http://pointclouds.org/) and boost. However, I'm developing a point cloud renderer plugin for Unreal at the moment, which you'll soon find on my portfolio/on the marketplace.
* This template is for static libraries (.lib) only (no dynamic DLLs).
* The included PCL/Boost libraries (and hence the whole plugin) is for Windows 64bit (Release-Build) only.

If you have problems using this template, feel free to contact me on my portfolio: http://www.valentinkraft.de/
