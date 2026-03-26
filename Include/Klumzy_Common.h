/* This file is apart of KlumzyEngine and is property of Klumzy Duk Gamez
 * Copyright (c) 2026 Klumzy Duk Gamez
 * See LICENSE.md for license details */

#if !defined __KLUMZY_COMMON_H__
#define __KLUMZY_COMMON_H__

#include <stdio.h>

#if defined __cplusplus
extern "C" {
#endif /* if defined __cplusplus */

#if defined _WIN32
#define KLUMZY_SYSTEM_WINDOWS
#else /* if defined _WIN32 */
#define KLUMZY_SYSTEM_UNKNOWN
#endif /* if defined _WIN32 */

#if defined __clang__
#define KLUMZY_COMPILER_CLANG
#elif defined __GNUC__ /* if defined __clang__ */
#define KLUMZY_COMPILER_GNU
#elif defined _MSC_VER /* if defined __clang__ */
#define KLUMZY_COMPILER_MSVC
#endif

#if defined KLUMZY_COMPILER_CLANG || defined KLUMZY_COMPILER_GNU
#if __SIZEOF_POINTER__ == 8
#define KLUMZY_BITNESS_64
#elif __SIZEOF_POINTER__ == 4 /* if __SIZEOF_POINTER__ == 8 */
#define KLUMZY_BITNESS_32
#else /* if __SIZEOF_POINTER__ == 8 */
#define KLUMZY_BITNESS_UNKNOWN
#endif /* if __SIZEOF_POINTER__ == 8 */
#elif defined KLUMZY_COMPILER_MSVC /* if defined KLUMZY_COMPILER_CLANG || defined KLUMZY_COMPILER_GNU */
#if defined _WIN64
#define KLUMZY_BITNESS_64
#elif defined _WIN32 /* if defined _WIN64 */
#define KLUMZY_BITNESS_32
#else /* if defined _WIN64 */
#define KLUMZY_BITNESS_UNKNOWN
#endif /* if defined _WIN64 */
#else /* if defined KLUMZY_COMPILER_CLANG || defined KLUMZY_COMPILER_GNU */
#define KLUMZY_BITNESS_UNKNOWN
#endif /* if defined KLUMZY_COMPILER_CLANG || defined KLUMZY_COMPILER_GNU */

#if defined KLUMZY_SYSTEM_WINDOWS
#if defined KLUMZY_EXPORT_DLL
#define KLUMZY_DLL __declspec(dllexport)
#else /* if defined KLUMZY_EXPORT_DLL */
#define KLUMZY_DLL __declspec(dllimport)
#endif /* if defined KLUMZY_EXPORT_DLL */
#else /* if defined KLUMZY_SYSTEM_WINDOWS */
#define KLUMZY_DLL
#endif /* if defined KLUMZY_SYSTEM_WINDOWS */

#if defined KLUMZY_COMPILER_CLANG || defined KLUMZY_COMPILER_GNU
#define KLUMZY_INLINE __attribute__((always_inline)) inline
#elif defined KLUMZY_COMPILER_MSVC /* if defined KLUMZY_COMPILER_CLANG || defined KLUMZY_COMPILER_GNU */
#define KLUMZY_INLINE __forceinline
#else /* if defined KLUMZY_COMPILER_CLANG || defined KLUMZY_COMPILER_GNU  */
#define KLUMZY_INLINE inline
#endif /* if defined KLUMZY_COMPILER_CLANG || defined KLUMZY_COMPILER_GNU */

typedef signed char Klumzy_Int8;
typedef signed short Klumzy_Int16;
typedef signed int Klumzy_Int32;
typedef signed long long Klumzy_Int64;

typedef unsigned char Klumzy_UInt8;
typedef unsigned short Klumzy_UInt16;
typedef unsigned int Klumzy_UInt32;
typedef unsigned long long Klumzy_UInt64;

typedef float Klumzy_Float32;
typedef double Klumzy_Float64;
typedef long double Klumzy_Float128;

typedef void Klumzy_Void;
typedef char Klumzy_Char;
typedef unsigned short Klumzy_WChar;
typedef unsigned char Klumzy_Bool;

#define Klumzy_False 0
#define Klumzy_True 1
#define Klumzy_Null 0

#if defined KLUMZY_BITNESS_64
typedef signed long long Klumzy_Int;
typedef unsigned long long Klumzy_UInt;
typedef double Klumzy_Float;
#elif defined KLUMZY_BITNESS_32 /* if defined KLUMZY_BITNESS_64 */
typedef signed int Klumzy_Int;
typedef unsigned int Klumzy_UInt;
typedef float Klumzy_Float;
#else /* if defined KLUMZY_BITNESS_64 */
typedef signed int Klumzy_Int;
typedef unsigned int Klumzy_UInt;
typedef float Klumzy_Float;
#endif /* if defined KLUMZY_BITNESS_64 */

typedef enum : Klumzy_UInt {
	__Klumzy_Result_SUCCESS_FIRST__,

	/* Success Start */
	Klumzy_Result_SUCCESS,
	/* Success End */

	__Klumzy_Result_SUCCESS_LAST__,
	__Klumzy_Result_WARNING_FIRST__,

	/* Warning Start */
	Klumzy_Result_WARNING_UNKNOWN,
	/* Warning End */

	__Klumzy_Result_WARNING_LAST__,
	__Klumzy_Result_ERROR_FIRST__,

	/* Error Start */
	Klumzy_Result_ERROR_UNKNOWN,
	/* Error End */

	__Klumzy_Result_ERROR_LAST__,
	__Klumzy_Result_FAILURE_FIRST__,

	/* Failure Start */
	Klumzy_Result_FAILURE_UNKNOWN,
	/* Failure End */

	__Klumzy_Result_FAILURE_LAST__,
	__Klumzy_Result_EXCEPTION_FIRST__,

	/* Exception Start */
	Klumzy_Result_EXCEPTION_UNKNOWN,
	/* Exception End */

	__Klumzy_Result_EXCEPTION_LAST__

} Klumzy_Result;

KLUMZY_INLINE Klumzy_Bool Klumzy_IsResultSuccess(Klumzy_Result r) { return r > __Klumzy_Result_SUCCESS_FIRST__ && r < __Klumzy_Result_SUCCESS_LAST__; }
KLUMZY_INLINE Klumzy_Bool Klumzy_IsResultWarning(Klumzy_Result r) { return r > __Klumzy_Result_WARNING_FIRST__ && r < __Klumzy_Result_WARNING_LAST__; }
KLUMZY_INLINE Klumzy_Bool Klumzy_IsResultError(Klumzy_Result r) { return r > __Klumzy_Result_ERROR_FIRST__ && r < __Klumzy_Result_ERROR_LAST__; }
KLUMZY_INLINE Klumzy_Bool Klumzy_IsResultFailure(Klumzy_Result r) { return r > __Klumzy_Result_FAILURE_FIRST__ && r < __Klumzy_Result_FAILURE_LAST__; }
KLUMZY_INLINE Klumzy_Bool Klumzy_IsResultException(Klumzy_Result r) { return r > __Klumzy_Result_EXCEPTION_FIRST__ && r < __Klumzy_Result_EXCEPTION_LAST__; }
KLUMZY_INLINE Klumzy_Bool Klumzy_DidResultPass(Klumzy_Result r) { return !Klumzy_IsResultError(r) && !Klumzy_IsResultFailure(r) && !Klumzy_IsResultException(r); }
KLUMZY_INLINE Klumzy_Bool Klumzy_DidResultFail(Klumzy_Result r) { return !Klumzy_IsResultSuccess(r) && !Klumzy_IsResultWarning(r); }
KLUMZY_DLL const Klumzy_Char* Klumzy_GetResultMessage(Klumzy_Result r);

#if defined __cplusplus
} /* extern "C" */
#endif /* if defined __cplusplus */

#endif /* if !defined __KLUMZY_COMMON_H__ */
