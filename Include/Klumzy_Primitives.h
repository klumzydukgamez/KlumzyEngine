/* This file is apart of KlumzyEngine and is property of Klumzy Duk Gamez
 * Copyright (c) 2026 Klumzy Duk Gamez
 * See LICENSE.md for license details */

#include "Klumzy_Macros.h"

#ifndef __KLUMZY_PRIMITIVES_H__
#define __KLUMZY_PRIMITIVES_H__

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

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

#endif /* ifndef __KLUMZY_PRIMITIVES_H__ */
