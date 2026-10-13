# README
## NVIDIA MAXINE VideoEffects SDK: API Source Code and Sample Applications

NVIDIA MAXINE Video Effects SDK enables AI-based visual effects that run with standard webcam input and can easily be integrated into video conference and content creation pipelines. The underlying deep learning models are optimized with NVIDIA AI using NVIDIA® TensorRT™ for high-performance inference, making it possible for developers to apply multiple effects in real-time applications.

The SDK has the following AI features:

- **Virtual Background**,which segments and masks the background areas in a video or image to enable AI-powered background removal, replacement, or blur.
- **Upscaler**, which is a very fast and light-weight method to deliver up to 4X high-quality scaled video with an adjustable sharpening parameter.
- **Video Noise Removal**, which removes low-light camera noise from a webcam video while preserving the texture details.

<p align="center">
<img src="https://github.com/NVIDIA-Maxine/Maxine-VFX-SDK/blob/main/resources/Denoise.gif" alt="NVIDIA Video Noise Removal" width="640" height="320"/>
 </p>

The SDK provides several sample applications that demonstrate the features listed above in real time by using offline videos.
- **AI Green Screen App**, which is a sample app that demonstrates the Virtual background feature.
- **UpscalePipeline App**, which is a sample app for the Upscaler feature.
- **DenoiseEffect App**, which is a sample app that demonstrates the Video Noise Removal feature.
- **BatchAigsEffect/BatchDenoiseEffect App**, which are sample apps that demonstrates the batching functionality of various features.

Video compression Artifact removal and Super Resolution are not supported on RTX Spark.
 
The input and output resolutions supported by the features of the SDK are listed below.
- The Upscaler feature supports any input resolution, and the following scaling factors: 4/3x (~1.33x), 1.5x, 2x, 3x  and 4x.
- The Video Noise Removal feature supports between 80p to 1080p as input resolutions.
- The Virtual Background and Background Blur features require that an input image/video be at least 288 pixels high.

NVIDIA MAXINE VideoEffects SDK is distributed in the following parts:

- This open source repository that includes the [SDK API and proxy linking source code](https://github.com/NVIDIA-Maxine/Maxine-VFX-SDK/tree/main/nvvfx), and [sample applications and their dependency libraries](https://github.com/NVIDIA-Maxine/Maxine-VFX-SDK/tree/main/samples).
- An installer hosted on [NVIDIA Maxine End-user Redistributables page](https://www.nvidia.com/broadcast-sdk-resources) that installs the SDK DLLs, the models, and the SDK dependency libraries.

Please refer to the [SDK System guide](https://docs.nvidia.com/deeplearning/maxine/vfx-sdk-system-guide/) for configuring and integrating the SDK, compiling and running the sample applications. Please visit the [NVIDIA MAXINE Video Effects SDK](https://developer.nvidia.com/maxine-getting-started) webpage for more information about the SDK.

## System requirements
The SDK is supported on NVIDIA GPUs that are based on the NVIDIA® Turing™, Ampere™, Ada™ or Blackwell™ architecture and have Tensor Cores.

* Windows OS supported: ARM64 Windows 11 or later
* Microsoft Visual Studio: 2017 (MSVC15.0) or later
* CMake: v3.12 or later
* NVIDIA Graphics Driver for Windows: 595 or later

## Compiling the sample apps

### Steps

The open source repository includes the source code to build the sample applications, and a proxy file NVVideoEffectsProxy.cpp to enable compilation without explicitly linking against the SDK DLL.

**Note: To download the models and runtime dependencies required by the features, you need to run the [SDK Installer](https://www.nvidia.com/broadcast-sdk-resources).**

1.	In the root folder of the downloaded source code, start the CMake GUI and specify the source folder and a build folder for the binary files.
*	For the source folder, ensure that the path ends in OSS.
*	For the build folder, ensure that the path ends in OSS/build.
2.  Use CMake to configure and generate the Visual Studio solution file.
*	Click Configure.
*	When prompted to confirm that CMake can create the build folder, click OK.
*	Select Visual Studio for the generator.
*	To complete configuring the Visual Studio solution file, click Finish.
*	To generate the Visual Studio Solution file, click Generate.
*	Verify that the build folder contains the NvVideoEffects_SDK.sln file.
3.  Use Visual Studio to generate the application binary .exe file from the NvVideoEffects_SDK.sln file.
*	In CMake, to open Visual Studio, click Open Project.
*	In Visual Studio, select Build > Build Solution.

## Documentation
Please refer to the online documentation guides -
* [NVIDIA Video Effects SDK Programming Guide](https://docs.nvidia.com/deeplearning/maxine/vfx-sdk-programming-guide/index.html)
* [NVIDIA Video Effects SDK System Guide](https://docs.nvidia.com/deeplearning/maxine/vfx-sdk-system-guide/index.html)
* [NvCVImage API Guide](https://docs.nvidia.com/deeplearning/maxine/nvcvimage-api-guide/index.html)

PDF versions of these guides are also available at the following locations - 
* [NVIDIA Video Effects SDK Programming Guide](https://docs.nvidia.com/deeplearning/maxine/pdf/vfx-sdk-programming-guide.pdf)
* [NVIDIA Video Effects SDK System Guide](https://docs.nvidia.com/deeplearning/maxine/pdf/vfx-sdk-system-guide.pdf)
* [NvCVImage API Guide](https://docs.nvidia.com/deeplearning/maxine/pdf/nvcvimage-api-guide.pdf)
