# Boost / PCL Unreal Third-Party Plugin
A template for a Unreal Engine plugin including a C++ Third Party library (on the example of the Point Cloud Library and Boost).

* PCL version: 1.8.1, 64bit
* Boost version: 1.64, 64bit
* Tested with UE Version: 4.18

For the corresponding tutorial please visit:

http://www.valentinkraft.de/including-the-point-cloud-library-into-unreal-tutorial/

# Installation
Please put this in your Engine/project plugin folder and activate the Plugin in Unreal (If you want to use it as an Engine plugin, you might have to include the plugin into a project once, so Unreal can compile your plugin before you can put it in your engine's plugin folder). When the engine asks you for recompiling, do it.

# Usage
If you want to use this as a starting point for your own plugin / other third party libraries please insert your Third-Party libraries in /Source/ThirdParty/ and change the PCL.Build.cs accordingly (details see tutorial, link above).

If you only want to use PCL/Boost functions in your project, you have to add the PCL/Boost module to your project's Build.cs file and enable RTTI and Exceptions as well:
```c#
PublicDependencyModuleNames.Add("PCL");

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

Please note:
* This Plugin doesn't provide a point cloud renderer. However, I'm developing a point cloud rendering at the moment, which you'll find on my portfolio.
* This template is for static libraries (.lib) only (no dynamic DLLs).
* The included PCL/Boost libraries are for Windows 64bit.

If you have problems using this template, feel free to contact me on my portfolio: http://www.valentinkraft.de/
