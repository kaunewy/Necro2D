// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Revision/Necro.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeNecro() {}

// ********** Begin Cross Module References ********************************************************
PAPERZD_API UClass* Z_Construct_UClass_APaperZDCharacter();
REVISION_API UClass* Z_Construct_UClass_ANecro();
REVISION_API UClass* Z_Construct_UClass_ANecro_NoRegister();
UPackage* Z_Construct_UPackage__Script_Revision();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ANecro *******************************************************************
void ANecro::StaticRegisterNativesANecro()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ANecro;
UClass* ANecro::GetPrivateStaticClass()
{
	using TClass = ANecro;
	if (!Z_Registration_Info_UClass_ANecro.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("Necro"),
			Z_Registration_Info_UClass_ANecro.InnerSingleton,
			StaticRegisterNativesANecro,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ANecro.InnerSingleton;
}
UClass* Z_Construct_UClass_ANecro_NoRegister()
{
	return ANecro::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ANecro_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Necro.h" },
		{ "ModuleRelativePath", "Necro.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANecro>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ANecro_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APaperZDCharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Revision,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANecro_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ANecro_Statics::ClassParams = {
	&ANecro::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANecro_Statics::Class_MetaDataParams), Z_Construct_UClass_ANecro_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ANecro()
{
	if (!Z_Registration_Info_UClass_ANecro.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANecro.OuterSingleton, Z_Construct_UClass_ANecro_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ANecro.OuterSingleton;
}
ANecro::ANecro(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ANecro);
ANecro::~ANecro() {}
// ********** End Class ANecro *********************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Revision_Source_Revision_Necro_h__Script_Revision_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ANecro, ANecro::StaticClass, TEXT("ANecro"), &Z_Registration_Info_UClass_ANecro, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANecro), 781544880U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Revision_Source_Revision_Necro_h__Script_Revision_1090823977(TEXT("/Script/Revision"),
	Z_CompiledInDeferFile_FID_Revision_Source_Revision_Necro_h__Script_Revision_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Revision_Source_Revision_Necro_h__Script_Revision_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
