/* This file is apart of KlumzyEngine and is property of Klumzy Duk Gamez
 * Copyright (c) 2026 Klumzy Duk Gamez
 * See LICENSE.md for license details */

#include "Klumzy_Primitives.h"
#include <math.h>

#ifndef __KLUMZY_CORE_VECTOR2_H__
#define __KLUMZY_CORE_VECTOR2_H__

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

typedef union {
	struct {
		Klumzy_Float32 x;
		Klumzy_Float32 y;
	};
	struct {
		Klumzy_Float32 w;
		Klumzy_Float32 h;
	};
	Klumzy_Float32 array[2];
} Klumzy_Core_Vector2;

KLUMZY_INLINE Klumzy_Float32 Klumzy_Core_Vector2_GetMagnitude(Klumzy_Core_Vector2 v) {
	return sqrtf(v.x * v.x + v.y * v.y);
}

KLUMZY_INLINE Klumzy_Core_Vector2 Klumzy_Core_Vector2_Add(Klumzy_Core_Vector2 a, Klumzy_Core_Vector2 b) {
	return {a.x + b.x, a.y + b.y};
}

KLUMZY_INLINE Klumzy_Core_Vector2 Klumzy_Core_Vector2_Subtract(Klumzy_Core_Vector2 a, Klumzy_Core_Vector2 b) {
	return {a.x - b.x, a.y - b.y};
}

KLUMZY_INLINE Klumzy_Core_Vector2 Klumzy_Core_Vector2_MultiplyByScalar(Klumzy_Core_Vector2 v, Klumzy_Float32 s) {
	return {v.x * s, v.y * s};
}

KLUMZY_INLINE Klumzy_Core_Vector2 Klumzy_Core_Vector2_DivideByScalar(Klumzy_Core_Vector2 v, Klumzy_Float32 s) {
	s = 1.0f / s;
	return {v.x * s, v.y * s};
}

KLUMZY_INLINE Klumzy_Core_Vector2 Klumzy_Core_Vector2_Negate(Klumzy_Core_Vector2 v) {
	return {-v.x, -v.y};
}

KLUMZY_INLINE Klumzy_Core_Vector2 Klumzy_Core_Vector2_Normalize(Klumzy_Core_Vector2 v) {
	Klumzy_Float32 s = 1.0f / Klumzy_Core_Vector2_GetMagnitude(v);
	return {v.x * s, v.y * s};
}

KLUMZY_INLINE Klumzy_Void Klumzy_Core_Vector2_AddInPlace(Klumzy_Core_Vector2* a, Klumzy_Core_Vector2 b) {
	a->x += b.x;
	a->y += b.y;
}

KLUMZY_INLINE Klumzy_Void Klumzy_Core_Vector2_SubtractInPlace(Klumzy_Core_Vector2* a, Klumzy_Core_Vector2 b) {
	a->x -= b.x;
	a->y -= b.y;
}

KLUMZY_INLINE Klumzy_Void Klumzy_Core_Vector2_MultiplyByScalarInPlace(Klumzy_Core_Vector2* v, Klumzy_Float32 s) {
	v->x *= s;
	v->y *= s;
}

KLUMZY_INLINE Klumzy_Void Klumzy_Core_Vector2_DivideByScalarInPlace(Klumzy_Core_Vector2* v, Klumzy_Float32 s) {
	s = 1.0f / s;
	v->x *= s;
	v->y *= s;
}

KLUMZY_INLINE Klumzy_Void Klumzy_Core_Vector2_NegateInPlace(Klumzy_Core_Vector2* v) {
	v->x = -v->x;
	v->y = -v->y;
}

KLUMZY_INLINE Klumzy_Void Klumzy_Core_Vector2_NormalizeInPlace(Klumzy_Core_Vector2* v) {
	Klumzy_Float32 s = 1.0f / Klumzy_Core_Vector2_GetMagnitude(*v);
	v->x *= s;
	v->y *= s;
}

#ifdef __cplusplus
} /* extern "C" { */
#endif /* ifdef __cplusplus */

#endif /* ifndef __KLUMZY_CORE_VECTOR2_H__ */
