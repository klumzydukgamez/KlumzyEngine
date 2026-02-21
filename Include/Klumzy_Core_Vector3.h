/* This file is apart of KlumzyEngine and is property of Klumzy Duk Gamez
 * Copyright (c) 2026 Klumzy Duk Gamez
 * See LICENSE.md for license details */

#include "Klumzy_Primitives.h"
#include <math.h>

#ifndef __KLUMZY_CORE_VECTOR3_H__
#define __KLUMZY_CORE_VECTOR3_H__

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

typedef union {
	struct {
		Klumzy_Float32 x;
		Klumzy_Float32 y;
		Klumzy_Float32 z;
	};
	struct {
		Klumzy_Float32 w;
		Klumzy_Float32 h;
		Klumzy_Float32 d;
	};
	Klumzy_Float32 array[3];
} Klumzy_Core_Vector3;

KLUMZY_INLINE Klumzy_Float32 Klumzy_Core_Vector3_GetMagnitude(Klumzy_Core_Vector3 v) {
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

KLUMZY_INLINE Klumzy_Core_Vector3 Klumzy_Core_Vector3_Add(Klumzy_Core_Vector3 a, Klumzy_Core_Vector3 b) {
	return {a.x + b.x, a.y + b.y, a.z + b.z};
}

KLUMZY_INLINE Klumzy_Core_Vector3 Klumzy_Core_Vector3_Subtract(Klumzy_Core_Vector3 a, Klumzy_Core_Vector3 b) {
	return {a.x - b.x, a.y - b.y, a.z - b.z};
}

KLUMZY_INLINE Klumzy_Core_Vector3 Klumzy_Core_Vector3_MultiplyByScalar(Klumzy_Core_Vector3 v, Klumzy_Float32 s) {
	return {v.x * s, v.y * s, v.z * s};
}

KLUMZY_INLINE Klumzy_Core_Vector3 Klumzy_Core_Vector3_DivideByScalar(Klumzy_Core_Vector3 v, Klumzy_Float32 s) {
	s = 1.0f / s;
	return {v.x * s, v.y * s, v.z * s};
}

KLUMZY_INLINE Klumzy_Core_Vector3 Klumzy_Core_Vector3_Negate(Klumzy_Core_Vector3 v) {
	return {-v.x, -v.y};
}

KLUMZY_INLINE Klumzy_Core_Vector3 Klumzy_Core_Vector3_Normalize(Klumzy_Core_Vector3 v) {
	Klumzy_Float32 s = 1.0f / Klumzy_Core_Vector3_GetMagnitude(v);
	return {v.x * s, v.y * s, v.z * s};
}

KLUMZY_INLINE Klumzy_Void Klumzy_Core_Vector3_AddInPlace(Klumzy_Core_Vector3* a, Klumzy_Core_Vector3 b) {
	a->x += b.x;
	a->y += b.y;
	a->z += b.z;
}

KLUMZY_INLINE Klumzy_Void Klumzy_Core_Vector3_SubtractInPlace(Klumzy_Core_Vector3* a, Klumzy_Core_Vector3 b) {
	a->x -= b.x;
	a->y -= b.y;
	a->z -= b.z;
}

KLUMZY_INLINE Klumzy_Void Klumzy_Core_Vector3_MultiplyByScalarInPlace(Klumzy_Core_Vector3* v, Klumzy_Float32 s) {
	v->x *= s;
	v->y *= s;
	v->z *= s;
}

KLUMZY_INLINE Klumzy_Void Klumzy_Core_Vector3_DivideByScalarInPlace(Klumzy_Core_Vector3* v, Klumzy_Float32 s) {
	s = 1.0f / s;
	v->x *= s;
	v->y *= s;
	v->z *= s;
}

KLUMZY_INLINE Klumzy_Void Klumzy_Core_Vector3_NegateInPlace(Klumzy_Core_Vector3* v) {
	v->x = -v->x;
	v->y = -v->y;
	v->z = -v->z;
}

KLUMZY_INLINE Klumzy_Void Klumzy_Core_Vector3_NormalizeInPlace(Klumzy_Core_Vector3* v) {
	Klumzy_Float32 s = 1.0f / Klumzy_Core_Vector3_GetMagnitude(*v);
	v->x *= s;
	v->y *= s;
	v->z *= s;
}

#ifdef __cplusplus
} /* extern "C" */
#endif /* ifdef __cplusplus */

#endif /* ifndef __KLUMZY_CORE_VECTOR3_H__ */
