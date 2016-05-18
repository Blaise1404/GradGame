#include "FMOD3DceptionPrivatePCH.h"
#include "FMOD3Dception.h"
#include "TBE_PluginSettings.h"

#if WITH_EDITOR
    #include "Internationalization.h"
    #include "ISettingsModule.h"
    #include "ISettingsSection.h"
#endif

void FMOD3DceptionImpl::StartupModule()
{
#if WITH_EDITOR
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "Plugins", "FMOD3Dception",
                                                                               FText::FromString("FMOD 3Dception"),
                                                                               FText::FromString("Settings for the 3Dception FMOD plugin"),
                                                                               GetMutableDefault<UTBE_PluginSettings>()
                                                                               );
        
        if (SettingsSection.IsValid())
        {
            SettingsSection->OnModified().BindRaw(this, &FMOD3DceptionImpl::HandleSettingsSaved);
        }
    }
#endif
    
}
 
void FMOD3DceptionImpl::ShutdownModule()
{
    
}

bool FMOD3DceptionImpl::HandleSettingsSaved()
{
    return true;
}

 
IMPLEMENT_MODULE(FMOD3DceptionImpl, FMOD3Dception)