# PCL_UnrealThirdPartyPlugin
A template for a Unreal Engine plugin including a C++ Third Party library (on the example of the Point Cloud Library and Boost).

For the corresponding tutorial please visit: http://www.valentinkraft.de/?p=447

# Installation / Usage
Please put this in your Unreal's plugin folder and rebuild the Visual Studio project files.

If you want to use this as a starting point for your own plugin / other third party libraries please insert them in /Source/ThirdParty/ and change the PCL.Build.cs accordingly.

Caution! I recommend to only use static libraries (.lib) with this plugin and no dynamic DLLs.
