// Copyright (c) 2015 Two Big Ears Ltd.
// All Rights Reserved
// TwoBigEars.com. support@twobigears.com

#pragma once

#include "GameFramework/Actor.h"
#include "TBE_3DceptionGlobal.generated.h"

UCLASS()
class ATBE_3DceptionGlobal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATBE_3DceptionGlobal();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
private:
    
    float fWorldScale;

};
