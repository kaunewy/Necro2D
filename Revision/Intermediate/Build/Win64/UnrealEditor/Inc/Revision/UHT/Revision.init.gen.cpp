// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRevision_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Revision;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Revision()
	{
		if (!Z_Registration_Info_UPackage__Script_Revision.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Revision",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x727A7B42,
				0x5901D855,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Revision.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Revision.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Revision(Z_Construct_UPackage__Script_Revision, TEXT("/Script/Revision"), Z_Registration_Info_UPackage__Script_Revision, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x727A7B42, 0x5901D855));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
