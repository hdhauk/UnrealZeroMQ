/** UE4 ZeroMQ Function Library
  *
  * Technology Platform for Research TPF
  * Faculty of Human Sciences
  * https://www.tpf.philhum.unibe.ch/
  * Copyright 2019 University of Bern. All Rights Reserved.
  *
  * Author: Roland Bruggmann
  *         roland.bruggmann@humdek.unibe.ch
  * 		https://github.com/brugr9
  *
  * Date: 	2020-01
  */


// Implementation following
// https://wiki.unrealengine.com/Blueprint_Function_Library,_Create_Your_Own_to_Share_With_Others
//
// Methods are expected to be static.

#include "ZeroMQBPFunctionLibrary.h"
#include "ZeroMQPrivatePCH.h" // that's how this methods become part of the plugin's module

//////////////////////////////////////////////////////////////////////////
// UZeroMQBPFunctionLibrary

UFUNCTION(BlueprintCallable, Category = "ZeroMQ")
FString UZeroMQBPFunctionLibrary::GetVersion(void)
{
	int major, minor, patch;
	zmq::version(&major, &minor, &patch);
	const FString versionString = FString::Printf(TEXT("v%d.%d.%d"), major, minor, patch);
	return versionString;
}