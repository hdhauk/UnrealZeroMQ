# UnrealZeroMQ
Unreal Engine plugin for ZeroMQ with bindings from [zmqcpp](https://github.com/zeromq/cppzmq).

## Usage
1. Copy this repository into the `Plugins` folder of your Unreal project.
2. Verify that the plugin is enabled in the plugin menu inside the Unreal Editor.
2. In your module's build file (`<your project name>.Build.cs`) add `ZeroMQ` to the module dependency list:
```c#
...
PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "ZeroMQ" });
                                                                                     // add this! ^^^^^^^^
...
```
4. Test that it works!
```cpp
# include <zmq.hpp>

...
// place this somewhere it'll be run (e.g. BeginPlay() of your gamemode or similar)
int major, minor, patch;
zmq::version(&major, &minor, &patch);
UE_LOG(LogTemp, Log, TEXT("ZeroMQ version: v%d.%d.%d), major, minor, patch);
...

```

## Support Unreal Engine 5
* Windows x64

## Support Unreal Engine 4
* Windows (x64 and x86)
* Linux
* MacOS
