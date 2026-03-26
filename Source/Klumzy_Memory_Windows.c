/* This file is apart of KlumzyEngine and is property of Klumzy Duk Gamez
 * Copyright (c) 2026 Klumzy Duk Gamez
 * See LICENSE.md for license details */

#include "Klumzy_Memory.h"

#if defined KLUMZY_SYSTEM_WINDOWS

#include <windows.h>

Klumzy_Result Klumzy_AllocateRawMemory(Klumzy_UInt size, Klumzy_Void** memory) {
	Klumzy_Void* ptr = VirtualAlloc(Klumzy_Null, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (ptr == Klumzy_Null) {
		return Klumzy_Result_FAILURE_UNKNOWN;
	}
	*memory = ptr;

	return Klumzy_Result_SUCCESS;
}

Klumzy_Result Klumzy_FreeRawMemory(Klumzy_UInt size, Klumzy_Void** memory) {
	BOOL b = VirtualFree(*memory, 0, MEM_RELEASE);
	if (b == Klumzy_False) {
		DWORD error = GetLastError();
		printf("VirtualFree failed with error: %lu\n", error);
		return Klumzy_Result_FAILURE_UNKNOWN;
	}
	*memory = Klumzy_Null;

	return Klumzy_Result_SUCCESS;
}

#endif /* if defined KLUMZY_SYSTEM_WINDOWS */
