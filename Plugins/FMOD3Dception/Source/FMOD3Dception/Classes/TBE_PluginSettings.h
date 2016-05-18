// Copyright (c), Firelight Technologies Pty, Ltd. 2012-2015.

#pragma once

#include "TBE_PluginSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UTBE_PluginSettings : public UObject
{
	GENERATED_UCLASS_BODY()

public:

	/**
	 * By default 1 unit = 1m in 3Dception. UE's default scale is 1 unit = 1cm. Setting the world scale to 0.01 (default) will ensure that 3Dception works with the same world scale as UE/FMOD.
	 */
	UPROPERTY(config, EditAnywhere, Category = InitSettings)
	float WorldScale;

};
