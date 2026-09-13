// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/C_GameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeC_GameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UECPP_API UClass* Z_Construct_UClass_AC_GameMode();
UECPP_API UClass* Z_Construct_UClass_AC_GameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_UECPP();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AC_GameMode **************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AC_GameMode;
UClass* AC_GameMode::GetPrivateStaticClass()
{
	using TClass = AC_GameMode;
	if (!Z_Registration_Info_UClass_AC_GameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("C_GameMode"),
			Z_Registration_Info_UClass_AC_GameMode.InnerSingleton,
			StaticRegisterNativesAC_GameMode,
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
	return Z_Registration_Info_UClass_AC_GameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AC_GameMode_NoRegister()
{
	return AC_GameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AC_GameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Game/C_GameMode.h" },
		{ "ModuleRelativePath", "Public/Game/C_GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA

// ********** Begin Class AC_GameMode constinit property declarations ******************************
// ********** End Class AC_GameMode constinit property declarations ********************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AC_GameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AC_GameMode_Statics
UObject* (*const Z_Construct_UClass_AC_GameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_UECPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AC_GameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AC_GameMode_Statics::ClassParams = {
	&AC_GameMode::StaticClass,
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
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AC_GameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AC_GameMode_Statics::Class_MetaDataParams)
};
void AC_GameMode::StaticRegisterNativesAC_GameMode()
{
}
UClass* Z_Construct_UClass_AC_GameMode()
{
	if (!Z_Registration_Info_UClass_AC_GameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AC_GameMode.OuterSingleton, Z_Construct_UClass_AC_GameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AC_GameMode.OuterSingleton;
}
AC_GameMode::AC_GameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AC_GameMode);
AC_GameMode::~AC_GameMode() {}
// ********** End Class AC_GameMode ****************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Game_C_GameMode_h__Script_UECPP_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AC_GameMode, AC_GameMode::StaticClass, TEXT("AC_GameMode"), &Z_Registration_Info_UClass_AC_GameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AC_GameMode), 4239575745U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Game_C_GameMode_h__Script_UECPP_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Game_C_GameMode_h__Script_UECPP_1721439457{
	TEXT("/Script/UECPP"),
	Z_CompiledInDeferFile_FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Game_C_GameMode_h__Script_UECPP_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Game_C_GameMode_h__Script_UECPP_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
