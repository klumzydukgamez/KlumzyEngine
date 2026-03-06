/* This file is apart of KlumzyEngine and is property of Klumzy Duk Gamez
 * Copyright (c) 2026 Klumzy Duk Gamez
 * See LICENSE.md for license details */

#ifndef __KLUMZY_RESULT_H__
#define __KLUMZY_RESULT_H__

#include "Klumzy_Common.h"

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

typedef enum : Klumzy_UInt32 {
	__Klumzy_Result_SUCCESS_FIRST__,

	/* Success */
	Klumzy_Result_SUCCESS,
	/* End Success */

	__Klumzy_Result_SUCCESS_LAST__,
	__Klumzy_Result_WARNING_FIRST__,

	/* Warning */
	Klumzy_Result_WARNING,
	/* End Warning */

	__Klumzy_Result_WARNING_LAST__,
	__Klumzy_Result_FAILURE_FIRST__,

	/* Failure */
	Klumzy_Result_FAILURE,
#ifdef KLUMZY_SYSTEM_WINDOWS
	Klumzy_Result_FAILURE_REGISTER_WNDCLASSEX,
	Klumzy_Result_FAILURE_UNREGISTER_WNDCLASSEX,
	Klumzy_Result_FAILURE_CREATE_WINDOW,
	Klumzy_Result_FAILURE_DESTROY_WINDOW,
	Klumzy_Result_FAILURE_CHOOSE_PIXEL_FORMAT,
	Klumzy_Result_FAILURE_SET_PIXEL_FORMAT,
	Klumzy_Result_FAILURE_CREATE_GL_CONTEXT,
	Klumzy_Result_FAILURE_SHARE_GL_LISTS,
#endif /* ifdef KLUMZY_SYSTEM_WINDOWS */
	/* End Failure */

	__Klumzy_Result_FAILURE_LAST__,
	__Klumzy_Result_ERROR_FIRST__,

	/* Error */
	Klumzy_Result_ERROR,
	Klumzy_Result_ERROR_OUT_OF_WINDOWS,
	/* End Error */

	__Klumzy_Result_ERROR_LAST__,
} Klumzy_Result;

KLUMZY_INLINE Klumzy_Bool Klumzy_IsResultSuccess(Klumzy_Result r) {
	if (r > __Klumzy_Result_SUCCESS_FIRST__ && r < __Klumzy_Result_SUCCESS_LAST__) {
		return Klumzy_True;
	} else {
		return Klumzy_False;
	}
}

KLUMZY_INLINE Klumzy_Bool Klumzy_IsResultWarning(Klumzy_Result r) {
	if (r > __Klumzy_Result_WARNING_FIRST__ && r < __Klumzy_Result_WARNING_LAST__) {
		return Klumzy_True;
	} else {
		return Klumzy_False;
	}
}

KLUMZY_INLINE Klumzy_Bool Klumzy_IsResultFailure(Klumzy_Result r) {
	if (r > __Klumzy_Result_FAILURE_FIRST__ && r < __Klumzy_Result_FAILURE_LAST__) {
		return Klumzy_True;
	} else {
		return Klumzy_False;
	}
}

KLUMZY_INLINE Klumzy_Bool Klumzy_IsResultError(Klumzy_Result r) {
	if (r > __Klumzy_Result_ERROR_FIRST__ && r < __Klumzy_Result_ERROR_LAST__) {
		return Klumzy_True;
	} else {
		return Klumzy_False;
	}
}

#ifdef __cplusplus
} /* extern "C" */
#endif /* ifdef __cplusplus */

#endif /* ifndef __KLUMZY_RESULT_H__ */
