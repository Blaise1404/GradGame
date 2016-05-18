// Copyright (c) 2015 Two Big Ears Ltd.
// All Rights Reserved
// TwoBigEars.com. support@twobigears.com

#include "FMOD3DceptionPrivatePCH.h"
#include "TBE_PluginUtils.h"

DEFINE_LOG_CATEGORY(Log3Dception);

#define TBE_GET_EXPORT(functionName, functionType)                                              \
    do                                                                                          \
    {                                                                                           \
        FString procName = #functionName;                                                       \
        functionName = (functionType) FPlatformProcess::GetDllExport(pDllHandle, *procName);    \
        if (!functionName) UE_LOG(Log3Dception, Error, TEXT("%s"), *(FString("TBE Global: Cannot find ") + #functionName + (" in 3Dception FMOD"))); \
    }                                                                                           \
    while(0)


_TBEngine_getVersionMinor TBEngine_getVersionMinor;
_TBEngine_getVersionMajor TBEngine_getVersionMajor;
_TBEngine_getVersionPatch TBEngine_getVersionPatch;
_TBEngine_isInitialised TBEngine_isInitialised;
_TBEngine_updateListener TBEngine_updateListener;
_TBEngine_setWorldScale TBEngine_setWorldScale;

_TBRoomMan_init TBRoomMan_init;
_TBRoomMan_addRoom TBRoomMan_addRoom;
_TBRoomMan_removeRoom TBRoomMan_removeRoom;
_TBRoomMan_setRoomCentre TBRoomMan_setRoomCentre;
_TBRoomMan_setRoomProperties TBRoomMan_setRoomProperties;
_TBRoomMan_setRoomAbsorption TBRoomMan_setRoomAbsorption;
_TBRoomMan_setRoomDiffuseZone TBRoomMan_setRoomDiffuseZone;
_TBRoomMan_update TBRoomMan_update;

bool TBE_Initialise3DceptionPlugin()
{
    if (!bTBE_3DceptionLoaded)
    {
        
        FString DllPath;
        
#if PLATFORM_WINDOWS
        
#   if PLATFORM_64BITS
        DllPath = FPaths::Combine(*FPaths::GamePluginsDir(), TEXT("FMODStudio/Binaries/Win64"), TEXT("3Dception_fmod.dll"));
#   else
        DllPath = FPaths::Combine(*FPaths::GamePluginsDir(), TEXT("FMODStudio/Binaries/Win32"), TEXT("3Dception_fmod.dll"));
#   endif
        
#elif PLATFORM_LINUX
        
#   if PLATFORM_64BITS
        DllPath = FPaths::Combine(*FPaths::GamePluginsDir(), TEXT("FMODStudio/Binaries/Linux/x86_64"), TEXT("lib3Dception_fmod.so"));
#   else
        DllPath = FPaths::Combine(*FPaths::GamePluginsDir(), TEXT("FMODStudio/Binaries/Linux/x86"), TEXT("lib3Dception_fmod.so"));
#   endif
        
#elif PLATFORM_MAC
        
        DllPath = FPaths::Combine(*FPaths::GamePluginsDir(), TEXT("FMODStudio/Binaries/Mac"), TEXT("lib3Dception_fmod.dylib"));
#else
        
#   error 3Dception FMOD UE Integration: Unimplemented platform!
        
#endif
        
        if (FPaths::FileExists(DllPath))
        {
            void * pDllHandle = FPlatformProcess::GetDllHandle(*DllPath);
            if (pDllHandle != NULL)
            {
                
                TBE_GET_EXPORT(TBEngine_getVersionMinor, _TBEngine_getVersionMinor);
                TBE_GET_EXPORT(TBEngine_getVersionMajor, _TBEngine_getVersionMajor);
                TBE_GET_EXPORT(TBEngine_getVersionPatch, _TBEngine_getVersionPatch);
                
                TBE_GET_EXPORT(TBEngine_isInitialised, _TBEngine_isInitialised);
                TBE_GET_EXPORT(TBEngine_updateListener, _TBEngine_updateListener);
                TBE_GET_EXPORT(TBEngine_setWorldScale, _TBEngine_setWorldScale);
                
                TBE_GET_EXPORT(TBRoomMan_init, _TBRoomMan_init);
                TBE_GET_EXPORT(TBRoomMan_addRoom, _TBRoomMan_addRoom);
                TBE_GET_EXPORT(TBRoomMan_removeRoom, _TBRoomMan_removeRoom);
                TBE_GET_EXPORT(TBRoomMan_setRoomCentre, _TBRoomMan_setRoomCentre);
                TBE_GET_EXPORT(TBRoomMan_setRoomProperties, _TBRoomMan_setRoomProperties);
                TBE_GET_EXPORT(TBRoomMan_setRoomAbsorption, _TBRoomMan_setRoomAbsorption);
                TBE_GET_EXPORT(TBRoomMan_setRoomDiffuseZone, _TBRoomMan_setRoomDiffuseZone);
                TBE_GET_EXPORT(TBRoomMan_update, _TBRoomMan_update);
    
                UE_LOG(Log3Dception, Log, TEXT("TBE Global: 3Dception FMOD plugin loaded."));
                
				bTBE_3DceptionLoaded = true;
            }
			else
			{
				bTBE_3DceptionLoaded = false;
			}
        }
        else
        {
			UE_LOG(Log3Dception, Error, TEXT("TBE Global: Unable to find 3Dception FMOD plugin in %s"), *DllPath);
			bTBE_3DceptionLoaded = false;
        }
    }
	else
	{
		bTBE_3DceptionLoaded = false;
	}

	return bTBE_3DceptionLoaded;
}
