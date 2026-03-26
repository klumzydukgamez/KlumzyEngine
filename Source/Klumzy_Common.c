/* This file is apart of KlumzyEngine and is property of Klumzy Duk Gamez
 * Copyright (c) 2026 Klumzy Duk Gamez
 * See LICENSE.md for license details */

#include "Klumzy_Common.h"

const Klumzy_Char* Klumzy_GetResultMessage(Klumzy_Result r) {
	switch (r) {
		case Klumzy_Result_SUCCESS:
			return "Succes";
		case Klumzy_Result_WARNING_UNKNOWN:
			return "Unknown warning";
		case Klumzy_Result_ERROR_UNKNOWN:
			return "Unknown error";
		case Klumzy_Result_FAILURE_UNKNOWN:
			return "Unknown failure";
		case Klumzy_Result_EXCEPTION_UNKNOWN:
			return "Unknown exception";
		default:
			return "";
	}
}
