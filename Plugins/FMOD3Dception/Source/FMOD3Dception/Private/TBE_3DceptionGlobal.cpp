// Copyright (c) 2015 Two Big Ears Ltd.
// All Rights Reserved
// TwoBigEars.com. support@twobigears.com

#include "FMOD3DceptionPrivatePCH.h"
#include "TBE_PluginUtils.h"
#include "TBE_3DceptionGlobal.h"
#include "TBE_PluginSettings.h"

ATBE_3DceptionGlobal::ATBE_3DceptionGlobal()
{
	PrimaryActorTick.bCanEverTick = true;
    
    fWorldScale = TBE_DEFAULT_WORLD_SCALE;
    
    auto pPluginSettings = GetDefault<UTBE_PluginSettings>();
    
    if (pPluginSettings)
    {
        fWorldScale = pPluginSettings->WorldScale;
    }
    
    TBE_Initialise3DceptionPlugin();
}

void ATBE_3DceptionGlobal::BeginPlay()
{
	Super::BeginPlay();
}


void ATBE_3DceptionGlobal::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	int ListenerIndex = 0;

	UWorld* ViewportWorld = nullptr;
	if (GEngine && GEngine->GameViewport)
	{
		ViewportWorld = GEngine->GameViewport->GetWorld();
	}

	if (ViewportWorld)
	{	
		APlayerController * PlayerController = ViewportWorld->GetFirstPlayerController();

		if (PlayerController)
		{
			ULocalPlayer * LocalPlayer = Cast<ULocalPlayer>(PlayerController->Player);
			if (LocalPlayer)
			{
				FVector Position;
				FVector ForwardVec;
				FVector RightVec;

				PlayerController->GetAudioListenerPosition(Position, ForwardVec, RightVec);
				FVector UpVec = FVector::CrossProduct(ForwardVec, RightVec);

				if (TBEngine_isInitialised && TBEngine_isInitialised())
				{	
					if (TBEngine_updateListener)
					{
						// Convert to 3Dception's co-ordinate system and scale
						TBEngine_updateListener(TBVector3(-Position.X * fWorldScale, Position.Z * fWorldScale, Position.Y * fWorldScale),
							TBVector3(-ForwardVec.X, ForwardVec.Z, ForwardVec.Y),
							TBVector3(-UpVec.X, UpVec.Z, UpVec.Y));
					}					
				}			
			}
		}
	}
}
