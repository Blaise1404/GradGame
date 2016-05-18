// Copyright (c) 2015 Two Big Ears Ltd.
// All Rights Reserved
// TwoBigEars.com. support@twobigears.com

#include "FMOD3DceptionPrivatePCH.h"
#include "TBE_Room.h"
#include "TBE_PluginUtils.h"
#include "TBE_PluginSettings.h"


ATBE_Room::ATBE_Room(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UBoxComponent>(TEXT("CollisionComp")))

{
    UBoxComponent* BoxCollisionComponent = CastChecked<UBoxComponent>(GetCollisionComponent());

	BoxCollisionComponent->ShapeColor = FColor(255, 0, 0, 255);
	BoxCollisionComponent->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f));

	static FName CollisionProfileName(TEXT("TBERoom"));
	BoxCollisionComponent->SetCollisionProfileName(CollisionProfileName);

    auto pSpriteComponent = GetSpriteComponent();
    
	if (pSpriteComponent)
	{
		pSpriteComponent->AttachParent = BoxCollisionComponent;
	}
    
    TBE_Initialise3DceptionPlugin();
    
    fWorldScale = TBE_DEFAULT_WORLD_SCALE;
    
    auto pPluginSettings = GetDefault<UTBE_PluginSettings>();
    
    if (pPluginSettings)
    {
         fWorldScale = pPluginSettings->WorldScale;
    }
	
	SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;

	Active = true;

}

#if WITH_EDITOR

void ATBE_Room::CheckForErrors()
{
	Super::CheckForErrors();
}

void ATBE_Room::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	setRoomProperties(RoomProperties);
}

void ATBE_Room::EditorApplyScale(const FVector& DeltaScale, const FVector* PivotLocation, bool bAltDown, bool bShiftDown, bool bCtrlDown)
{
	const FVector ModifiedScale = DeltaScale * (AActor::bUsePercentageBasedScaling ? 500.0f : 5.0f);

	UBoxComponent * BoxComponent = Cast<UBoxComponent>(GetRootComponent());
	if (bCtrlDown)
	{
		// CTRL+Scaling modifies trigger collision height.  This is for convenience, so that height
		// can be changed without having to use the non-uniform scaling widget (which is
		// inaccessable with spacebar widget cycling).
		FVector Extent = BoxComponent->GetUnscaledBoxExtent() + FVector(0, 0, ModifiedScale.X);
		Extent.Z = FMath::Max(0.0f, Extent.Z);
		BoxComponent->SetBoxExtent(Extent);
	}
	else
	{
		FVector Extent = BoxComponent->GetUnscaledBoxExtent() + FVector(ModifiedScale.X, ModifiedScale.Y, ModifiedScale.Z);
		Extent.X = FMath::Max(0.0f, Extent.X);
		Extent.Y = FMath::Max(0.0f, Extent.Y);
		Extent.Z = FMath::Max(0.0f, Extent.Z);
		BoxComponent->SetBoxExtent(Extent);
	}
}

#endif // WITH_EDITOR

void ATBE_Room::Tick(float DeltaSeconds)
{
	if (TBRoomMan_update)
	{
		TBRoomMan_update();
	}
}

void ATBE_Room::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UBoxComponent * BoxComponent = Cast<UBoxComponent>(GetRootComponent());
	
	iRoomId = GetUniqueID();

    TBVector3 CentrePosition, UpVector, ForwardVector, Scale;
    CentrePosition = FVectorToTBVector3(BoxComponent->GetComponentLocation());
    Scale = FVectorToTBVector3(2 * BoxComponent->GetScaledBoxExtent());
    UpVector = FVectorToTBVector3(BoxComponent->GetUpVector());
    ForwardVector = FVectorToTBVector3(BoxComponent->GetForwardVector());

    // 3Dception's room manager system requires a unique tag for each room
	if (TBRoomMan_addRoom && TBRoomMan_setRoomCentre)
	{
		TBRoomMan_addRoom(iRoomId);
		TBRoomMan_setRoomCentre(iRoomId, CentrePosition * fWorldScale, ForwardVector, UpVector, Scale * fWorldScale);
	}
    
    setRoomProperties(RoomProperties);
}

void ATBE_Room::BeginDestroy() 
{	
	if (TBRoomMan_removeRoom)
	{
		TBRoomMan_removeRoom(iRoomId);
	}
	
	Super::BeginDestroy();
}

void ATBE_Room::setTransformAndScale(FTransform Transform, FVector Extent, FVector Scale)
{
	UBoxComponent * BoxComponent = Cast<UBoxComponent>(GetRootComponent());

	iRoomId = GetUniqueID();

	BoxComponent->SetWorldTransform(Transform);
	BoxComponent->SetBoxExtent(Extent);

    TBVector3 CentrePosition, UpVector, ForwardVector, RoomScale;
    CentrePosition = FVectorToTBVector3(BoxComponent->GetComponentLocation());
    RoomScale = FVectorToTBVector3(2 * BoxComponent->GetScaledBoxExtent());
    UpVector = FVectorToTBVector3(BoxComponent->GetUpVector());
    ForwardVector = FVectorToTBVector3(BoxComponent->GetForwardVector());
    
	if (TBRoomMan_setRoomCentre)
	{
		TBRoomMan_setRoomCentre(iRoomId, CentrePosition * fWorldScale, ForwardVector, UpVector, RoomScale * fWorldScale);
	}
}

void ATBE_Room::setRoomProperties(FTBE_RoomProperties TBERoomProperties)
{
    
    iRoomId = GetUniqueID();
    
	RoomProperties.RoomHFReflection = FMath::Clamp(TBERoomProperties.RoomHFReflection, 0.f, 1.f);
	RoomProperties.RoomAmpReflection = FMath::Clamp(TBERoomProperties.RoomAmpReflection, 0.f, 2.f);
	RoomProperties.CeilingReflection = FMath::Clamp(TBERoomProperties.CeilingReflection, 0.f, 1.f);
	RoomProperties.FloorReflection = FMath::Clamp(TBERoomProperties.FloorReflection, 0.f, 1.f);
	RoomProperties.RightWallReflection = FMath::Clamp(TBERoomProperties.RightWallReflection, 0.f, 1.f);
	RoomProperties.FrontWallReflection = FMath::Clamp(TBERoomProperties.FrontWallReflection, 0.f, 1.f);
	RoomProperties.LeftWallReflection = FMath::Clamp(TBERoomProperties.LeftWallReflection, 0.f, 1.f);
	RoomProperties.RearWallReflection = FMath::Clamp(TBERoomProperties.RearWallReflection, 0.f, 1.f);
	RoomProperties.DiffuseZoneSize = FMath::Max(0.f, TBERoomProperties.DiffuseZoneSize);

	TBRoomProperties TBRoomProps;
	TBRoomProps.fRoomHfReflection = RoomProperties.RoomHFReflection;
	TBRoomProps.fRoomAmpReflection = RoomProperties.RoomAmpReflection;
	TBRoomProps.fDiffuseZoneSize = RoomProperties.DiffuseZoneSize;

	switch (TBERoomProperties.Preset)
	{
	case ETBEPresets::Default:
		RoomProperties.CeilingReflection = 1;
		RoomProperties.FloorReflection = 1;
		RoomProperties.RightWallReflection = 1;
		RoomProperties.FrontWallReflection = 1;
		RoomProperties.LeftWallReflection = 1;
		RoomProperties.RearWallReflection = 1;
		break;
	case ETBEPresets::ConcreteRoom:
		RoomProperties.CeilingReflection = 0.94f;
		RoomProperties.FloorReflection = 0.94f;
		RoomProperties.RightWallReflection = 0.94f;
		RoomProperties.FrontWallReflection = 0.94f;
		RoomProperties.LeftWallReflection = 0.94f;
		RoomProperties.RearWallReflection = 0.94f;
		break;
	case ETBEPresets::RecordingStudio:
		RoomProperties.CeilingReflection = 0.23f;
		RoomProperties.FloorReflection = 0.75f;
		RoomProperties.RightWallReflection = 0.42f;
		RoomProperties.FrontWallReflection = 0.25f;
		RoomProperties.LeftWallReflection = 0.42f;
		RoomProperties.RearWallReflection = 0.42f;
		break;
	case ETBEPresets::Glass:
		RoomProperties.CeilingReflection = 0.97f;
		RoomProperties.FloorReflection = 0.97;
		RoomProperties.RightWallReflection = 0.97f;
		RoomProperties.FrontWallReflection = 0.97f;
		RoomProperties.LeftWallReflection = 0.97f;
		RoomProperties.RearWallReflection = 0.97f;
		break;
	case ETBEPresets::LivingRoom:
		RoomProperties.CeilingReflection = 0.96f;
		RoomProperties.FloorReflection = 0.93;
		RoomProperties.RightWallReflection = 0.78f;
		RoomProperties.FrontWallReflection = 0.78f;
		RoomProperties.LeftWallReflection = 0.78f;
		RoomProperties.RearWallReflection = 0.78f;
		break;
	case ETBEPresets::Outdoor:
		RoomProperties.CeilingReflection = 0.01f;
		RoomProperties.FloorReflection = 0.94;
		RoomProperties.RightWallReflection = 0.01f;
		RoomProperties.FrontWallReflection = 0.01f;
		RoomProperties.LeftWallReflection = 0.01f;
		RoomProperties.RearWallReflection = 0.01f;
		break;
	}

	TBRoomProps.fReflectionCeiling = RoomProperties.CeilingReflection;
	TBRoomProps.fReflectionFloor = RoomProperties.FloorReflection;
	TBRoomProps.fReflectionRWall = RoomProperties.RightWallReflection;
	TBRoomProps.fReflectionFWall = RoomProperties.FrontWallReflection;
	TBRoomProps.fReflectionLWall = RoomProperties.LeftWallReflection;
	TBRoomProps.fReflectionBWall = RoomProperties.RearWallReflection;
    
	if (TBRoomMan_setRoomProperties)
	{
		TBRoomMan_setRoomProperties(iRoomId, TBRoomProps);
	}
}



