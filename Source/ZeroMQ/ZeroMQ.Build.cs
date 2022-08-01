// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System;
using System.IO;
using System.Diagnostics;

public class ZeroMQ : ModuleRules
{
    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "..", "..", "ThirdParty")); }
    }

    private string ZeroMQRootPath
    {
        get { return Path.GetFullPath(Path.Combine(ThirdPartyPath, "libzmq_4.3.1")); }
    }

    public void AddZeroMQ(ReadOnlyTargetRules Target)
    {
        // add headers
        PublicIncludePaths.Add(Path.Combine(ZeroMQRootPath, "include"));

        // tell library that it is statically linked
        PublicDefinitions.Add("ZMQ_STATIC");

        string staticLibrary = "";
        if (Target.Platform == UnrealTargetPlatform.Win64) {
            staticLibrary = Path.Combine(ZeroMQRootPath, "Windows", "x64", "libzmq-v141-mt-s-4_3_2.lib");
        } else if (Target.Platform == UnrealTargetPlatform.Linux) {
            staticLibrary = Path.Combine(ZeroMQRootPath, "Linux", "libzmq.so");
            PublicAdditionalLibraries.Add("stdc++");
        } else if (Target.Platform == UnrealTargetPlatform.Mac) {
            staticLibrary = Path.Combine(ZeroMQRootPath, "MacOS", "libzmq.a");
        } else {
            Console.WriteLine("unsupported target platform: %s", Target.Platform);
            Debug.Assert(false);
        }

        bEnableExceptions = true;

        Console.WriteLine("Using ZeroMQ static library: {0}", staticLibrary);
        PublicAdditionalLibraries.Add(staticLibrary);
    }


    public ZeroMQ(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new string[] { "Core" });
        AddZeroMQ(Target);

    }
}
