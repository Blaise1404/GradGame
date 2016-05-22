// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
struct FSubstanceInstanceDesc;
struct FSubstanceFloatInputDesc;
struct FSubstanceIntInputDesc;
#ifdef SUBSTANCECORE_SubstanceGraphInstance_generated_h
#error "SubstanceGraphInstance.generated.h already included, missing '#pragma once' in SubstanceGraphInstance.h"
#endif
#define SUBSTANCECORE_SubstanceGraphInstance_generated_h

#define BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_80_GENERATED_BODY \
	friend SUBSTANCECORE_API class UScriptStruct* Z_Construct_UScriptStruct_FSubstanceInstanceDesc(); \
	SUBSTANCECORE_API static class UScriptStruct* StaticStruct();


#define BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_64_GENERATED_BODY \
	friend SUBSTANCECORE_API class UScriptStruct* Z_Construct_UScriptStruct_FSubstanceFloatInputDesc(); \
	SUBSTANCECORE_API static class UScriptStruct* StaticStruct();


#define BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_48_GENERATED_BODY \
	friend SUBSTANCECORE_API class UScriptStruct* Z_Construct_UScriptStruct_FSubstanceIntInputDesc(); \
	SUBSTANCECORE_API static class UScriptStruct* StaticStruct();


#define BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_35_GENERATED_BODY \
	friend SUBSTANCECORE_API class UScriptStruct* Z_Construct_UScriptStruct_FSubstanceInputDesc(); \
	SUBSTANCECORE_API static class UScriptStruct* StaticStruct();


#define BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_93_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetInputImg) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InputName); \
		P_GET_OBJECT(UObject,Z_Param_Value); \
		P_FINISH; \
		*(bool*)Z_Param__Result=this->SetInputImg(Z_Param_InputName,Z_Param_Value); \
	} \
 \
	DECLARE_FUNCTION(execGetInstanceDesc) \
	{ \
		P_FINISH; \
		*(FSubstanceInstanceDesc*)Z_Param__Result=this->GetInstanceDesc(); \
	} \
 \
	DECLARE_FUNCTION(execGetFloatInputDesc) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Identifier); \
		P_FINISH; \
		*(FSubstanceFloatInputDesc*)Z_Param__Result=this->GetFloatInputDesc(Z_Param_Identifier); \
	} \
 \
	DECLARE_FUNCTION(execGetIntInputDesc) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Identifier); \
		P_FINISH; \
		*(FSubstanceIntInputDesc*)Z_Param__Result=this->GetIntInputDesc(Z_Param_Identifier); \
	} \
 \
	DECLARE_FUNCTION(execGetInputFloat) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Identifier); \
		P_FINISH; \
		*(TArray<float>*)Z_Param__Result=this->GetInputFloat(Z_Param_Identifier); \
	} \
 \
	DECLARE_FUNCTION(execGetInputInt) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Identifier); \
		P_FINISH; \
		*(TArray<int32>*)Z_Param__Result=this->GetInputInt(Z_Param_Identifier); \
	} \
 \
	DECLARE_FUNCTION(execSetInputFloat) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Identifier); \
		P_GET_TARRAY_REF(float,Z_Param_Out_InputValues); \
		P_FINISH; \
		this->SetInputFloat(Z_Param_Identifier,Z_Param_Out_InputValues); \
	} \
 \
	DECLARE_FUNCTION(execSetInputInt) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Identifier); \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		this->SetInputInt(Z_Param_Identifier,Z_Param_Out_Value); \
	} \
 \
	DECLARE_FUNCTION(execGetInputType) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InputName); \
		P_FINISH; \
		*(TEnumAsByte<ESubstanceInputType>*)Z_Param__Result=this->GetInputType(Z_Param_InputName); \
	} \
 \
	DECLARE_FUNCTION(execGetInputNames) \
	{ \
		P_FINISH; \
		*(TArray<FString>*)Z_Param__Result=this->GetInputNames(); \
	}


#define BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_93_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetInputImg) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InputName); \
		P_GET_OBJECT(UObject,Z_Param_Value); \
		P_FINISH; \
		*(bool*)Z_Param__Result=this->SetInputImg(Z_Param_InputName,Z_Param_Value); \
	} \
 \
	DECLARE_FUNCTION(execGetInstanceDesc) \
	{ \
		P_FINISH; \
		*(FSubstanceInstanceDesc*)Z_Param__Result=this->GetInstanceDesc(); \
	} \
 \
	DECLARE_FUNCTION(execGetFloatInputDesc) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Identifier); \
		P_FINISH; \
		*(FSubstanceFloatInputDesc*)Z_Param__Result=this->GetFloatInputDesc(Z_Param_Identifier); \
	} \
 \
	DECLARE_FUNCTION(execGetIntInputDesc) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Identifier); \
		P_FINISH; \
		*(FSubstanceIntInputDesc*)Z_Param__Result=this->GetIntInputDesc(Z_Param_Identifier); \
	} \
 \
	DECLARE_FUNCTION(execGetInputFloat) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Identifier); \
		P_FINISH; \
		*(TArray<float>*)Z_Param__Result=this->GetInputFloat(Z_Param_Identifier); \
	} \
 \
	DECLARE_FUNCTION(execGetInputInt) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Identifier); \
		P_FINISH; \
		*(TArray<int32>*)Z_Param__Result=this->GetInputInt(Z_Param_Identifier); \
	} \
 \
	DECLARE_FUNCTION(execSetInputFloat) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Identifier); \
		P_GET_TARRAY_REF(float,Z_Param_Out_InputValues); \
		P_FINISH; \
		this->SetInputFloat(Z_Param_Identifier,Z_Param_Out_InputValues); \
	} \
 \
	DECLARE_FUNCTION(execSetInputInt) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Identifier); \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		this->SetInputInt(Z_Param_Identifier,Z_Param_Out_Value); \
	} \
 \
	DECLARE_FUNCTION(execGetInputType) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InputName); \
		P_FINISH; \
		*(TEnumAsByte<ESubstanceInputType>*)Z_Param__Result=this->GetInputType(Z_Param_InputName); \
	} \
 \
	DECLARE_FUNCTION(execGetInputNames) \
	{ \
		P_FINISH; \
		*(TArray<FString>*)Z_Param__Result=this->GetInputNames(); \
	}


#define BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_93_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUSubstanceGraphInstance(); \
	friend SUBSTANCECORE_API class UClass* Z_Construct_UClass_USubstanceGraphInstance(); \
	public: \
	DECLARE_CLASS(USubstanceGraphInstance, UObject, COMPILED_IN_FLAGS(0), 0, SubstanceCore, SUBSTANCECORE_API) \
	DECLARE_SERIALIZER(USubstanceGraphInstance) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const { return const_cast<USubstanceGraphInstance*>(this); }


#define BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_93_INCLASS \
	private: \
	static void StaticRegisterNativesUSubstanceGraphInstance(); \
	friend SUBSTANCECORE_API class UClass* Z_Construct_UClass_USubstanceGraphInstance(); \
	public: \
	DECLARE_CLASS(USubstanceGraphInstance, UObject, COMPILED_IN_FLAGS(0), 0, SubstanceCore, SUBSTANCECORE_API) \
	DECLARE_SERIALIZER(USubstanceGraphInstance) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const { return const_cast<USubstanceGraphInstance*>(this); }


#define BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_93_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	SUBSTANCECORE_API USubstanceGraphInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USubstanceGraphInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(SUBSTANCECORE_API, USubstanceGraphInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USubstanceGraphInstance); \
private: \
	/** Private copy-constructor, should never be used */ \
	SUBSTANCECORE_API USubstanceGraphInstance(const USubstanceGraphInstance& InCopy); \
public:


#define BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_93_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	SUBSTANCECORE_API USubstanceGraphInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	SUBSTANCECORE_API USubstanceGraphInstance(const USubstanceGraphInstance& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(SUBSTANCECORE_API, USubstanceGraphInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USubstanceGraphInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USubstanceGraphInstance)


#define BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_90_PROLOG
#define BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_93_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_93_RPC_WRAPPERS \
	BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_93_INCLASS \
	BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_93_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_93_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_93_RPC_WRAPPERS_NO_PURE_DECLS \
	BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_93_INCLASS_NO_PURE_DECLS \
	BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h_93_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class SubstanceGraphInstance."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BUILD_15_GA_UE4_UserContent_4_10_Plugins_Substance_Source_SubstanceCore_Classes_SubstanceGraphInstance_h


#define FOREACH_ENUM_ESUBSTANCEINPUTTYPE(op) \
	op(SIT_Float) \
	op(SIT_Float2) \
	op(SIT_Float3) \
	op(SIT_Float4) \
	op(SIT_Integer) \
	op(SIT_Image) \
	op(SIT_Unused_6) \
	op(SIT_Unused_7) \
	op(SIT_Integer2) \
	op(SIT_Integer3) \
	op(SIT_Integer4) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
