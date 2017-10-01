# Boost / PCL Unreal Third-Party Plugin
A template for a Unreal Engine plugin including a C++ Third Party library (on the example of the Point Cloud Library and Boost).

* PCL version: 1.8.1
* Boost version: 1.64

For the corresponding tutorial please visit:

http://www.valentinkraft.de/including-the-point-cloud-library-into-unreal-tutorial/

# Installation / Quick Usage
Please put this in your Unreal's/project's plugin folder rebuild the Visual Studio project files and activate the Plugin in Unreal (you might have to include the plugin into a project once, so Unreal can compile your plugin before you can put it in your engine's plugin folder).

If you want to use this as a starting point for your own plugin / other third party libraries please insert your Third-Party libraries in /Source/ThirdParty/ and change the PCL.Build.cs accordingly (details see tutorial, link above).

If you only want to use PCL/Boost functions in your project, you have to add the PCL/Boost module to your project's Build.cs file and enable RTTI and Exceptions as well:
```c-sharp
PublicDependencyModuleNames.Add("PCL");

bUseRTTI = true;
bEnableExceptions = true;
```

Please note: This template is for static libraries (.lib) only (no dynamic DLLs).
