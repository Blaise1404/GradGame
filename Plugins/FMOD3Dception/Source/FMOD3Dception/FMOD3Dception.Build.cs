using UnrealBuildTool;
using System.IO;
 
public class FMOD3Dception : ModuleRules
{
    public FMOD3Dception(TargetInfo Target)
    {
        PrivateIncludePaths.AddRange(new string[] { "FMOD3Dception/Private" });
        PublicIncludePaths.AddRange(new string[] { "FMOD3Dception/Public" });
 
        PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine",
				}
				);
 
        DynamicallyLoadedModuleNames.AddRange(new string[] { "FMOD3Dception" });
    }
}