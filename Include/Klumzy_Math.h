/* This file is apart KlumzyEngine and is property of Klumzy Duk Gamez
 * Copyright (c) 2026 Klumzy Duk Gamez
 * See LICENSE.md for license details */

#if !defined __KLUMZY_MATH_H__
#define __KLUMZY_MATH_H__

#include "Klumzy_Common.h"
#include <math.h>
#include <stdlib.h>

#if defined __cplusplus
extern "C" {
#endif /* if defined __cplusplus */

#define Klumzy_PI 3.1415926535897932384626433833 /* could replace with: acosl(-1.0L) */
#define Klumzy_TAU 6.2831853071795864769252867666
#define Klumzy_E 2.7182818284590452353602874714

KLUMZY_INLINE Klumzy_Int32 Klumzy_AbsOfInt32(Klumzy_Int32 x) { return abs(x); }
KLUMZY_INLINE Klumzy_Int64 Klumzy_AbsOfInt64(Klumzy_Int64 x) { return llabs(x); }
KLUMZY_INLINE Klumzy_Float32 Klumzy_AbsOfFloat32(Klumzy_Float32 x) { return fabsf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_AbsOfFloat64(Klumzy_Float64 x) { return fabs(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_SinOfFloat32(Klumzy_Float32 x) { return sinf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_SinOfFloat64(Klumzy_Float64 x) { return sin(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_CosOfFloat32(Klumzy_Float32 x) { return cosf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_CosOfFloat64(Klumzy_Float64 x) { return cos(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_TanOfFloat32(Klumzy_Float32 x) { return tanf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_TanOfFloat64(Klumzy_Float64 x) { return tan(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_ArcSinOfFloat32(Klumzy_Float32 x) { return asinf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_ArcSinOfFloat64(Klumzy_Float64 x) { return asin(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_ArcCosOfFloat32(Klumzy_Float32 x) { return acosf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_ArcCosOfFloat64(Klumzy_Float64 x) { return acos(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_ArcTanOfFloat32(Klumzy_Float32 x) { return atanf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_ArcTanOfFloat64(Klumzy_Float64 x) { return atan(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_ArcTan2OfFloat32(Klumzy_Float32 y, Klumzy_Float32 x) { return atan2f(y, x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_ArcTan2OfFloat64(Klumzy_Float64 y, Klumzy_Float64 x) { return atan2f(y, x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_HyperSinOfFloat32(Klumzy_Float32 x) { return sinhf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_HyperSinOfFloat64(Klumzy_Float64 x) { return sinh(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_HyperCosOfFloat32(Klumzy_Float32 x) { return coshf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_HyperCosOfFloat64(Klumzy_Float64 x) { return cosh(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_HyperTanOfFloat32(Klumzy_Float32 x) { return tanhf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_HyperTanOfFloat64(Klumzy_Float64 x) { return tanh(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_HyperArcSinOfFloat32(Klumzy_Float32 x) { return asinhf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_HyperArcSinOfFloat64(Klumzy_Float64 x) { return asinh(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_HyperArcCosOfFloat32(Klumzy_Float32 x) { return acoshf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_HyperArcCosOfFloat64(Klumzy_Float64 x) { return acosh(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_HyperArcTanOfFloat32(Klumzy_Float32 x) { return atanhf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_HyperArcTanOfFloat64(Klumzy_Float64 x) { return atanh(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_SqrtOfFloat32(Klumzy_Float32 x) { return sqrtf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_SqrtOfFloat64(Klumzy_Float64 x) { return sqrt(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_FloorOfFloat32(Klumzy_Float32 x) { return floorf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_FloorOfFloat64(Klumzy_Float64 x) { return floor(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_CeilOfFloat32(Klumzy_Float32 x) { return ceilf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_CeilOfFloat64(Klumzy_Float64 x) { return ceil(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_RoundFloat32(Klumzy_Float32 x) { return roundf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_RoundFloat64(Klumzy_Float64 x) { return round(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_LogOfFloat32(Klumzy_Float32 x) { return logf(x); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_LogOfFloat64(Klumzy_Float64 x) { return logl(x); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_PowOfFloat32(Klumzy_Float32 x, Klumzy_Float32 y) { return powf(x, y); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_PowOfFloat64(Klumzy_Float64 x, Klumzy_Float64 y) { return pow(x, y); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_FModOfFloat32(Klumzy_Float32 x, Klumzy_Float32 y) { return fmodf(x, y); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_FModOfFloat64(Klumzy_Float64 x, Klumzy_Float32 y) { return fmod(x, y); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_ModFOfFloat32(Klumzy_Float32 x, Klumzy_Float32* y) { return modff(x, y); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_ModFOfFloat64(Klumzy_Float64 x, Klumzy_Float64* y) { return modf(x, y); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_DegreesToRadiansOfFloat32(Klumzy_Float32 x) { return x * ((Klumzy_Float32)Klumzy_PI / 180.0f); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_DegreesToRadiansOfFloat64(Klumzy_Float64 x) { return x * ((Klumzy_Float64)Klumzy_PI / 180.0); }

KLUMZY_INLINE Klumzy_Float32 Klumzy_RadiansToDegreesOfFloat32(Klumzy_Float32 x) { return x * (180.0f / (Klumzy_Float32)Klumzy_PI); }
KLUMZY_INLINE Klumzy_Float64 Klumzy_RadiansToDegreesOfFloat64(Klumzy_Float64 x) { return x * (180.0 / (Klumzy_Float64)Klumzy_PI); }

KLUMZY_INLINE Klumzy_Float32 AngularDifferenceOfFloat32(Klumzy_Float32 from, Klumzy_Float32 to) {
	Klumzy_Float32 difference = fmodf(to - from, (Klumzy_Float32)Klumzy_TAU);
	return fmodf(2.0f * difference, (Klumzy_Float32)Klumzy_TAU) - difference;
}
KLUMZY_INLINE Klumzy_Float32 AngularDifferenceOfFloat64(Klumzy_Float64 from, Klumzy_Float64 to) {
	Klumzy_Float64 difference = fmod(to - from, (Klumzy_Float64)Klumzy_TAU);
	return fmod(2.0 * difference, (Klumzy_Float64)Klumzy_TAU) - difference;
}

KLUMZY_INLINE Klumzy_Float32 Klumzy_LinearInterpolateFloat32(Klumzy_Float32 from, Klumzy_Float32 to, Klumzy_Float32 weight) { return from + (to - from) * weight; }
KLUMZY_INLINE Klumzy_Float64 Klumzy_LinearInterpolateFloat64(Klumzy_Float64 from, Klumzy_Float64 to, Klumzy_Float64 weight) { return from + (to - from) * weight; }

KLUMZY_INLINE Klumzy_Float32 Klumzy_LinearInterpolateRadiansOfFloat32(Klumzy_Float32 from, Klumzy_Float32 to, Klumzy_Float32 weight) { return from + AngularDifferenceOfFloat32(from, to) * weight; }
KLUMZY_INLINE Klumzy_Float64 Klumzy_LinearInterpolateRadiansOfFloat64(Klumzy_Float64 from, Klumzy_Float64 to, Klumzy_Float64 weight) { return from + AngularDifferenceOfFloat64(from, to) * weight; }

KLUMZY_INLINE Klumzy_Bool Klumzy_IsFloat32EqualWithTolerance(Klumzy_Float32 x, Klumzy_Float32 y, Klumzy_Float32 tolerance) {
	if (x == y) {
		return Klumzy_True;
	}

	return Klumzy_AbsOfFloat32(x - y) < tolerance;
}
KLUMZY_INLINE Klumzy_Bool Klumzy_IsFloat64EqualWithTolerance(Klumzy_Float64 x, Klumzy_Float64 y, Klumzy_Float64 tolerance) {
	if (x == y) {
		return Klumzy_True;
	}

	return Klumzy_AbsOfFloat64(x - y) < tolerance;
}

typedef union {
	struct {
		Klumzy_Float32 x, y;
	};
	struct {
		Klumzy_Float32 w, h;
	};
	Klumzy_Float32 array[2];
} Klumzy_Vector2;

typedef union {
	struct {
		Klumzy_Float32 x, y, z;
	};
	Klumzy_Float32 array[3];
} Klumzy_Vector3;

typedef union {
	struct {
		Klumzy_Float32 x, y, z, w;
	};
	Klumzy_Float32 array[4];
} Klumzy_Vector4;

typedef struct {
	Klumzy_Vector3 rows[3];
} Klumzy_Matrix3x3;

typedef struct {
	Klumzy_Vector4 rows[4];
} Klumzy_Matrix4x4;

typedef union {
	struct {
		Klumzy_Float32 x, y, z, w;
	};
	Klumzy_Float32 array[4];
} Klumzy_Quaternion;

typedef union {
	struct {
		Klumzy_Float32 r, g, b, a;
	};
	Klumzy_Float32 array[4];
} Klumzy_Color;

#if defined __cplusplus
} /* extern "C" */
#endif /* if defined __cplusplus */

#endif /* if !defined __KLUMZY_MATH_H__ */
