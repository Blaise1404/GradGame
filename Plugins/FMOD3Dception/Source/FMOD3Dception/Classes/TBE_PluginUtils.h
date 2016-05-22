
// Copyright (c) 2015 Two Big Ears Ltd.
// All Rights Reserved
// TwoBigEars.com. support@twobigears.com

#pragma once

DECLARE_LOG_CATEGORY_EXTERN(Log3Dception, Log, All);


////////////////////////////////////////////////////////
//////// STRUCTURES
////////////////////////////////////////////////////////

typedef struct TBVector3
{
    float x;
    float y;
    float z;
    
    TBVector3() { }
    
    TBVector3(float valX, float valY, float valZ)
    : x(valX), y(valY), z(valZ)
    { }
    
    inline TBVector3 operator*(const TBVector3& vector) const
    {
        return TBVector3(x * vector.x, y * vector.y, z * vector.z);
    }
    
    inline TBVector3 operator*(float value) const
    {
        return TBVector3(x * value, y * value, z * value);
    }

    
} TBVector3;

typedef struct TBRoomProperties
{
    float fRoomHfReflection;    /*!< Level of high frequency reflections of the total room */
    float fRoomAmpReflection;   /*!< Level of reflections of the total room */
    float fReflectionCeiling;   /*!< Level reflections off the ceiling */
    float fReflectionFloor;     /*!< Level reflections off the floor */
    float fReflectionRWall;     /*!< Level reflections off the right wall */
    float fReflectionFWall;     /*!< Level reflections off the front wall */
    float fReflectionLWall;     /*!< Level reflections off the left wall */
    float fReflectionBWall;     /*!< Level reflections off the back/rear wall */
    float fDiffuseZoneSize;     /*!< Size of the diffuse zone in game units */
    
    TBRoomProperties() : fRoomHfReflection(0), fRoomAmpReflection(0), fReflectionCeiling(0),
    fReflectionFloor(0), fReflectionRWall(0), fReflectionFWall(0), fReflectionLWall(0), fReflectionBWall(0),
    fDiffuseZoneSize(1)
    {
        //
    }
    
} TBRoomProperties;

///////////////////////////////////////////////////////
//////// FUNCTION POINTERS
////////////////////////////////////////////////////////

typedef int (* _TBEngine_getVersionMinor)();
extern _TBEngine_getVersionMinor TBEngine_getVersionMinor;

typedef int (* _TBEngine_getVersionMajor)();
extern _TBEngine_getVersionMajor TBEngine_getVersionMajor;

typedef int (* _TBEngine_getVersionPatch)();
extern _TBEngine_getVersionPatch TBEngine_getVersionPatch;

typedef bool (* _TBEngine_isInitialised)();
extern _TBEngine_isInitialised TBEngine_isInitialised;

typedef void (* _TBEngine_updateListener)(TBVector3, TBVector3, TBVector3);
extern _TBEngine_updateListener TBEngine_updateListener;

typedef void (* _TBEngine_setWorldScale)(float);
extern _TBEngine_setWorldScale TBEngine_setWorldScale;

typedef void (* _TBEngine_setWorldScale)(float);
extern _TBEngine_setWorldScale TBEngine_setWorldScale;

typedef void (* _TBRoomMan_init)();
extern _TBRoomMan_init TBRoomMan_init;

typedef void (* _TBRoomMan_addRoom)(int iRoomId);
extern _TBRoomMan_addRoom TBRoomMan_addRoom;

typedef void (* _TBRoomMan_removeRoom)(int iRoomId);
extern _TBRoomMan_removeRoom TBRoomMan_removeRoom;

typedef void (* _TBRoomMan_setRoomCentre) (int iRoomId, TBVector3 CentrePosition, TBVector3 ForwardVector, TBVector3 UpVector, TBVector3 Scale);
extern _TBRoomMan_setRoomCentre TBRoomMan_setRoomCentre;

typedef void (* _TBRoomMan_setRoomProperties) (int iRoomId, TBRoomProperties RoomProperties);
extern _TBRoomMan_setRoomProperties TBRoomMan_setRoomProperties;

typedef void (* _TBRoomMan_setRoomAbsorption)(int iRoomId, float fRoomAmpDampening, float fRoomHfReflection);
extern _TBRoomMan_setRoomAbsorption TBRoomMan_setRoomAbsorption;

typedef void (* _TBRoomMan_setRoomDiffuseZone) (int iRoomId, float fDiffuseZoneSize);
extern _TBRoomMan_setRoomDiffuseZone TBRoomMan_setRoomDiffuseZone;

typedef void (* _TBRoomMan_update)();
extern _TBRoomMan_update TBRoomMan_update;


///////////////////////////////////////////////////////
//////// VARIABLES & HELPER FUNCTIONS
////////////////////////////////////////////////////////

static const float TBE_DEFAULT_WORLD_SCALE = 0.01f;

/// If TBE_Initialise3DceptionPlugin succeeds, this is set to true
static bool bTBE_3DceptionLoaded = false;

/// Load DLL and initialise all function pointers
bool TBE_Initialise3DceptionPlugin();

inline TBVector3 FVectorToTBVector3(const FVector & Vector)
{
    return TBVector3(-Vector.X, Vector.Z, Vector.Y);
}
