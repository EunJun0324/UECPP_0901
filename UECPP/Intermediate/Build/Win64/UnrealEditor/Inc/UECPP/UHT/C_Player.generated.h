// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actors/Characters/C_Player.h"

#ifdef UECPP_C_Player_generated_h
#error "C_Player.generated.h already included, missing '#pragma once' in C_Player.h"
#endif
#define UECPP_C_Player_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AC_Player ****************************************************************
struct Z_Construct_UClass_AC_Player_Statics;
UECPP_API UClass* Z_Construct_UClass_AC_Player_NoRegister();

#define FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Actors_Characters_C_Player_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAC_Player(); \
	friend struct ::Z_Construct_UClass_AC_Player_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend UECPP_API UClass* ::Z_Construct_UClass_AC_Player_NoRegister(); \
public: \
	DECLARE_CLASS2(AC_Player, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UECPP"), Z_Construct_UClass_AC_Player_NoRegister) \
	DECLARE_SERIALIZER(AC_Player)


#define FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Actors_Characters_C_Player_h_12_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AC_Player(AC_Player&&) = delete; \
	AC_Player(const AC_Player&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AC_Player); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AC_Player); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AC_Player) \
	NO_API virtual ~AC_Player();


#define FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Actors_Characters_C_Player_h_9_PROLOG
#define FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Actors_Characters_C_Player_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Actors_Characters_C_Player_h_12_INCLASS_NO_PURE_DECLS \
	FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Actors_Characters_C_Player_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AC_Player;

// ********** End Class AC_Player ******************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_User_Desktop_UECPP_0901_UECPP_Source_UECPP_Public_Actors_Characters_C_Player_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
