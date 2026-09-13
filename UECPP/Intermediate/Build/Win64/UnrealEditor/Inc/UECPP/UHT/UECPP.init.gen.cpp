// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUECPP_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_UECPP;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_UECPP()
	{
		if (!Z_Registration_Info_UPackage__Script_UECPP.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/UECPP",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000000,
			0xF22CFCCB,
			0x2A6677FF,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_UECPP.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_UECPP.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_UECPP(Z_Construct_UPackage__Script_UECPP, TEXT("/Script/UECPP"), Z_Registration_Info_UPackage__Script_UECPP, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xF22CFCCB, 0x2A6677FF));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
