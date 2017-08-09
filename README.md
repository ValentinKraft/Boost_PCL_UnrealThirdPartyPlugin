# Boost / PCL Unreal Third-Party Plugin
A template for a Unreal Engine plugin including a C++ Third Party library (on the example of the Point Cloud Library and Boost).
PCL version: 1.8.1
Boost version: 1.64

For the corresponding tutorial please visit: http://www.valentinkraft.de/including-the-point-cloud-library-into-unreal-tutorial/

# Installation / Usage
Please put this in your Unreal's plugin folder and rebuild the Visual Studio project files.

If you want to use this as a starting point for your own plugin / other third party libraries please insert them in /Source/ThirdParty/ and change the PCL.Build.cs accordingly.

Caution! I recommend to use static libraries (.lib) only with this plugin and no dynamic DLLs.
