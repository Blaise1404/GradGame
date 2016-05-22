#pragma once
 
#include "ModuleManager.h"
 
class FMOD3DceptionImpl : public IModuleInterface
{
public:

	void StartupModule();
	void ShutdownModule();
    bool HandleSettingsSaved();
};