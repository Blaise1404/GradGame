// Copyright (c) 2015 Two Big Ears Ltd.
// All Rights Reserved
// TwoBigEars.com. support@twobigears.com

#pragma once

#include "Engine/TriggerBase.h"
#include "TBE_Room.generated.h"

/** Presets for 3Dception rooms */
UENUM(BlueprintType)
namespace ETBEPresets
{
	enum Room
	{	
		Default UMETA(DisplayName = "Default"),
		Custom UMETA(DisplayName = "Custom"),
		ConcreteRoom UMETA(DisplayName = "Concrete Room"),
		RecordingStudio UMETA(DisplayName = "Recordng Studio"),
		Glass UMETA(DisplayName = "Glass"),
		LivingRoom UMETA(DisplayName = "Living Room"),
		Outdoor UMETA(DisplayName = "Outdoor"),
	};
}

USTRUCT()
struct FTBE_RoomProperties
{
	GENERATED_USTRUCT_BODY()

	/** Size of the diffuse zone: the area around the room where the reflections gradually die out */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TwoBigEars")
	float DiffuseZoneSize;

	/** High frequency reflection for the room, between 0 and 1. 1 is maximum reflection */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TwoBigEars")
	float RoomHFReflection;

	/** Amplitude reflection for the room, between 0 and 2. 2 is maximum reflection */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TwoBigEars")
	float RoomAmpReflection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TwoBigEars")
	TEnumAsByte<ETBEPresets::Room> Preset;

	/** Intesnity of reflections for the left wall, between 0 and 1. 1 is maximum reflection */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TwoBigEars")
	float LeftWallReflection;

	/** Intesnity of reflections for the right wall, between 0 and 1. 1 is maximum reflection */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TwoBigEars")
	float RightWallReflection;

	/** Intesnity of reflections for the front wall, between 0 and 1. 1 is maximum reflection */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TwoBigEars")
	float FrontWallReflection;

	/** Intesnity of reflections for the rear wall, between 0 and 1. 1 is maximum reflection */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TwoBigEars")
	float RearWallReflection;

	/** Intesnity of reflections for the ceiling, between 0 and 1. 1 is maximum reflection */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TwoBigEars")
	float CeilingReflection;

	/** Intesnity of reflections for the floor, between 0 and 1. 1 is maximum reflection */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TwoBigEars")
	float FloorReflection;

	FTBE_RoomProperties()
	{
		DiffuseZoneSize = 1;
		RoomHFReflection = 0.8;
		RoomAmpReflection = 0.8;
		Preset = ETBEPresets::Custom;
		LeftWallReflection = 1;
		RightWallReflection = 1;
		FrontWallReflection = 1;
		RearWallReflection = 1;
		CeilingReflection = 1;
		FloorReflection= 1;
	}
};

/**
 * Sets up 3Dception's room modelling zones
 */
UCLASS(Blueprintable, hidecategories = (Advanced, Attachment, Volume, Physics, Actor, Input))
class ATBE_Room : public ATriggerBase
{
	GENERATED_UCLASS_BODY()
	
	/** Change room reflection and diffuse properties */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TwoBigEars")
	FTBE_RoomProperties RoomProperties;

	bool Active;

	virtual void Tick(float DeltaSeconds) override;

	virtual void PostInitializeComponents() override;

	virtual void BeginDestroy() override;

public:

	/** Set room reflection properties, preset and diffuse zone size */
	UFUNCTION(BlueprintCallable, Category = "TwoBigEars")
	void setRoomProperties(FTBE_RoomProperties TBERoomProperties);

	/** Set room transform, extent and scale */
	void setTransformAndScale(FTransform Transform, FVector Extent, FVector Scale);

private:
    
	/** Rooms require unique IDs, as ints */
	int iRoomId;
    float fWorldScale;

#if CPP
protected:

#if WITH_EDITOR

	virtual void CheckForErrors() override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void EditorApplyScale(const FVector& DeltaScale, const FVector* PivotLocation, bool bAltDown, bool bShiftDown, bool bCtrlDown) override;

#endif // WITH_EDITOR

#endif // CPP
	
};
