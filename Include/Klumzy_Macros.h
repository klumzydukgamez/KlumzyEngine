/* This file is apart of KlumzyEngine and is property of Klumzy Duk Gamez
 * Coyright (c) 2026 Klumzy Duk Gamez
 * See LICENSE.md for license details */

#ifndef __KLUMZY_MACROS_H__
#define __KLUMZY_MACROS_H__

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

#endif /* ifndef __KLUMZY_MACROS_H__ */
