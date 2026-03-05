/* This file is apart of KlumzyEngine and is property of Klumzy Duk Gamez
 * Coyright (c) 2026 Klumzy Duk Gamez
 * See LICENSE.md for license details */

#ifndef __KLUMZY_COMMON_H__
#define __KLUMZY_COMMON_H__

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

#ifdef __GNUC__
#define KLUMZY_COMPILER_GNU
#endif /* ifdef __GNUC__ */

#ifdef __clang__
#define KLUMZY_COMPILER_CLANG
#endif /* ifdef __clang__ */

#if defined(_MSC_VER) && !defined(KLUMZY_COMPILER_CLANG)
#define KLUMZY_COMPILER_MSVC
#endif /* ifdef _MSC_VER */

#if defined(KLUMZY_COMPILER_GNU) || defined(KLUMZY_COMPILER_CLANG)
#if __SIZEOF_POINTER__ == 8
#define KLUMZY_SYSTEM_BITNESS_64
#elif __SIZEOF_POINTER__ == 4 /* if __SIZEOF_POINTER__ == 8 */
#define KLUMZY_SYSTEM_BITNESS_32
#endif /* if __SIZEOF_POINTER__ == 8 */
#elifdef KLUMZY_COMPILER_MSVC /* if defined(KLUMZY_COMPILER_GNU) || defined(KLUMZY_COMPILER_CLANG) */
#ifdef _WIN64
#define KLUMZY_SYSTEM_BITNESS_64
#elifdef _WIN32 /* ifdef _WIN64 */
#define KLUMZY_SYSTEM_BITNESS_32
#endif /* ifdef _WIN64 */
#endif /* if defined(KLUMZY_COMPILER_GNU) || defined(KLUMZY_COMPILER_CLANG) */

#ifdef _WIN32
#define KLUMZY_SYSTEM_WINDOWS
#endif /* KLUMZY_SYSTEM_WINDOWS */

#ifdef KLUMZY_SYSTEM_WINDOWS
#ifdef KLUMZY_EXPORT_DLL
#define KLUMZY_DLL __declspec(dllexport)
#else /* ifdef KLUMZY_EXPORT_DLL */
#define KLUMZY_DLL __declspec(dllimport)
#endif /* ifdef KLUMZY_EXPORT_DLL */
#else /* ifdef KLUMZY_SYSTEM_WINDOWS */
#define KLMZY_DLL
#endif /* ifdef KLUMZY_SYSTEM_WINDOWS */

#if defined(KLUMZY_COMPILER_GNU) || defined(KLUMZY_COMPILER_CLANG)
#define KLUMZY_INLINE __attribute__((always_inline)) inline
#elifdef KLUMZY_COMPILER_MSVC /* if defined(KLUMZY_COMPILER_GNU) || defined(KLUMZY_COMPILER_CLANG) */
#define KLUMZY_INLINE __forceinline
#else /* if defined(KLUMZY_COMPILER_GNU) || defined(KLUMZY_COMPILER_CLANG) */
#define KLUMZY_INLINE inline
#endif /* if defined(KLUMZY_COMPILER_GNU) || defined(KLUMZY_COMPILER_CLANG) */

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

#ifdef KLUMZY_SYSTEM_BITNESS_64
typedef signed long long Klumzy_Int;
typedef unsigned long long Klumzy_UInt;
typedef double Klumzy_Float;
#elifdef KLUMZY_SYSTEM_BITNESS_32 /* ifdef KLUMZY_SYSTEM_BITNESS_64 */
typedef signed int Klumzy_Int;
typedef unsigned int Klumzy_UInt;
typedef float Klumzy_Float;
#endif /* ifdef KLUMZY_SYSTEM_BITNESS_64 */

#ifdef __cplusplus
} /* extern "C" */
#endif /* ifdef __cplusplus */

#endif /* ifndef __KLUMZY_COMMON_H__ */
