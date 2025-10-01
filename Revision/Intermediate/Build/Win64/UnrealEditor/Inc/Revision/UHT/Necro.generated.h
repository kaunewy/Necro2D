// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Necro.h"

#ifdef REVISION_Necro_generated_h
#error "Necro.generated.h already included, missing '#pragma once' in Necro.h"
#endif
#define REVISION_Necro_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ANecro *******************************************************************
REVISION_API UClass* Z_Construct_UClass_ANecro_NoRegister();

#define FID_Revision_Source_Revision_Necro_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANecro(); \
	friend struct Z_Construct_UClass_ANecro_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend REVISION_API UClass* Z_Construct_UClass_ANecro_NoRegister(); \
public: \
	DECLARE_CLASS2(ANecro, APaperZDCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Revision"), Z_Construct_UClass_ANecro_NoRegister) \
	DECLARE_SERIALIZER(ANecro)


#define FID_Revision_Source_Revision_Necro_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ANecro(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ANecro(ANecro&&) = delete; \
	ANecro(const ANecro&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANecro); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANecro); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANecro) \
	NO_API virtual ~ANecro();


#define FID_Revision_Source_Revision_Necro_h_12_PROLOG
#define FID_Revision_Source_Revision_Necro_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Revision_Source_Revision_Necro_h_15_INCLASS_NO_PURE_DECLS \
	FID_Revision_Source_Revision_Necro_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ANecro;

// ********** End Class ANecro *********************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Revision_Source_Revision_Necro_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
