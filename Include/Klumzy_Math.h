/* This file is apart of KlumzyEngine and is property of Klumzy Duk Gamez
 * Copyright (c) 2026 Klumzy Duk Gamez
 * See LICENSE.md for license details */

#ifndef __KLUMZY_MATH_H__
#define __KLUMZY_MATH_H__

#include "Klumzy_Common.h"

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

typedef union {
	struct {
		Klumzy_Float32 x, y;
	};
	struct {
		Klumzy_Float32 w, h;
	};
	Klumzy_Float32 array[2];
} Klumzy_Vector2;

KLUMZY_INLINE Klumzy_Vector2 Klumzy_Vector2AddVector2(Klumzy_Vector2 a, Klumzy_Vector2 b) {
	return (Klumzy_Vector2){a.x + b.x, a.y + b.y};
}

KLUMZY_INLINE Klumzy_Vector2 Klumzy_Vector2SubtractVector2(Klumzy_Vector2 a, Klumzy_Vector2 b) {
	return (Klumzy_Vector2){a.x - b.x, a.y - b.y};
}

KLUMZY_INLINE Klumzy_Vector2 Klumzy_Vector2MultiplyScalar(Klumzy_Vector2 v, Klumzy_Float32 s) {
	return (Klumzy_Vector2){v.x * s, v.y * s};
}

KLUMZY_INLINE Klumzy_Vector2 Klumzy_Vector2DivideScalar(Klumzy_Vector2 v, Klumzy_Float32 s) {
	s = 1.0f / s;
	return (Klumzy_Vector2){v.x * s, v.y * s};
}

KLUMZY_INLINE Klumzy_Void Klumzy_Vector2AddVector2InPlace(Klumzy_Vector2* a, Klumzy_Vector2 b) {
	a->x += b.x;
	a->y += b.y;
}

KLUMZY_INLINE Klumzy_Void Klumzy_Vector2SubtractVector2InPlace(Klumzy_Vector2* a, Klumzy_Vector2 b) {
	a->x -= b.x;
	a->y -= b.y;
}

KLUMZY_INLINE Klumzy_Void Klumzy_Vector2MultiplyScalarInPlace(Klumzy_Vector2* v, Klumzy_Float32 s) {
	v->x *= s;
	v->y *= s;
}

KLUMZY_INLINE Klumzy_Void Klumzy_Vector2DivideScalarInPlace(Klumzy_Vector2* v, Klumzy_Float32 s) {
	s = 1.0f / s;
	v->x *= s;
	v->y *= s;
}

typedef union {
	struct {
		Klumzy_Float32 x, y, z;
	};
	struct {
		Klumzy_Float32 w, h, d;
	};
	Klumzy_Float32 array[3];
} Klumzy_Vector3;

KLUMZY_INLINE Klumzy_Vector3 Klumzy_Vector3AddVector3(Klumzy_Vector3 a, Klumzy_Vector3 b) {
	return (Klumzy_Vector3){a.x + b.x, a.y + b.y, a.z + b.z};
}

KLUMZY_INLINE Klumzy_Vector3 Klumzy_Vector3SubtractVector3(Klumzy_Vector3 a, Klumzy_Vector3 b) {
	return (Klumzy_Vector3){a.x - b.x, a.y - b.y, a.z - b.z};
}

KLUMZY_INLINE Klumzy_Vector3 Klumzy_Vector3MultiplyScalar(Klumzy_Vector3 v, Klumzy_Float32 s) {
	return (Klumzy_Vector3){v.x * s, v.y * s, v.z * s};
}

KLUMZY_INLINE Klumzy_Vector3 Klumzy_Vector3DivideScalar(Klumzy_Vector3 v, Klumzy_Float32 s) {
	s = 1.0f / s;
	return (Klumzy_Vector3){v.x * s, v.y * s, v.z * s};
}

KLUMZY_INLINE Klumzy_Void Klumzy_Vector3AddVector3InPlace(Klumzy_Vector3* a, Klumzy_Vector3 b) {
	a->x += b.x;
	a->y += b.y;
	a->z *= b.z;
}

KLUMZY_INLINE Klumzy_Void Klumzy_Vector3SubtractVector3InPlace(Klumzy_Vector3* a, Klumzy_Vector3 b) {
	a->x -= b.x;
	a->y -= b.y;
	a->z -= b.z;
}

KLUMZY_INLINE Klumzy_Void Klumzy_Vector3MultiplyScalarInPlace(Klumzy_Vector3* v, Klumzy_Float32 s) {
	v->x *= s;
	v->y *= s;
	v->z *= s;
}

KLUMZY_INLINE Klumzy_Void Klumzy_Vector3DivideScalarInPlace(Klumzy_Vector3* v, Klumzy_Float32 s) {
	s = 1.0f / s;
	v->x *= s;
	v->y *= s;
	v->z *= s;
}

#ifdef __cplusplus
} /* extern "C" */
#endif /* ifdef __cplusplus */

#endif /* ifndef __KLUMZY_MATH_H__ */
