/** UE4 ZeroMQ Function Library
  *
  * Technology Platform for Research TPF
  * Faculty of Human Sciences
  * https://www.tpf.philhum.unibe.ch/
  * Copyright 2019 University of Bern. All Rights Reserved.
  *
  * Author: Roland Bruggmann
  *         roland.bruggmann@humdek.unibe.ch
  * 		    https://github.com/brugr9
  *
  * Date: 	2020-01
  */

// Blueprint Function Library, methods are expected to be static.
// https://wiki.unrealengine.com/Blueprint_Function_Library,_Create_Your_Own_to_Share_With_Others


#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <zmq.hpp>

#include "ZeroMQBPFunctionLibrary.generated.h"


UCLASS()
class UZeroMQBPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


	UFUNCTION(BlueprintCallable, Category = "ZeroMQ")
		static FString GetVersion();

};
