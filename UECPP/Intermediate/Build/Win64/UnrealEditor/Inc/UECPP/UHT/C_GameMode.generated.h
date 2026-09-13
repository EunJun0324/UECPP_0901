// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/C_GameMode.h"

#ifdef UECPP_C_GameMode_generated_h
#error "C_GameMode.generated.h already included, missing '#pragma once' in C_GameMode.h"
#endif
#define UECPP_C_GameMode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AC_GameMode **************************************************************
struct Z_Construct_UClass_AC_GameMode_Statics;
UECPP_API UClass* Z_Construct_UClass_AC_GameMode_NoRegister();

#define FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Game_C_GameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAC_GameMode(); \
	friend struct ::Z_Construct_UClass_AC_GameMode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend UECPP_API UClass* ::Z_Construct_UClass_AC_GameMode_NoRegister(); \
public: \
	DECLARE_CLASS2(AC_GameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/UECPP"), Z_Construct_UClass_AC_GameMode_NoRegister) \
	DECLARE_SERIALIZER(AC_GameMode)


#define FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Game_C_GameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AC_GameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AC_GameMode(AC_GameMode&&) = delete; \
	AC_GameMode(const AC_GameMode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AC_GameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AC_GameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AC_GameMode) \
	NO_API virtual ~AC_GameMode();


#define FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Game_C_GameMode_h_12_PROLOG
#define FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Game_C_GameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Game_C_GameMode_h_15_INCLASS_NO_PURE_DECLS \
	FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Game_C_GameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AC_GameMode;

// ********** End Class AC_GameMode ****************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Game_C_GameMode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
