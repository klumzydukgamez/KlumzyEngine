/* This file is apart of KlumzyEngine and is property of Klumzy Duk Gamez
 * Copyright (c) 2026 Klumzy Duk Gamez
 * See LICENSE.md for license details */

#include <Klumzy.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	Klumzy_Display display;

	Klumzy_Result result = Klumzy_StartupDisplay(&display);
	if (Klumzy_IsResultSuccess(result) == Klumzy_Null) {
		printf("Failed to startup display: %d\n", result);
	}

	Klumzy_Window* window;
	for (Klumzy_UInt32 i = 0; i < 2; i++) {
		result = Klumzy_OpenWindow(&display, &window);
		if (Klumzy_IsResultSuccess(result) == Klumzy_Null) {
			printf("Failed to open window (%d): %d\n", i, result);
		}
	}

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) != Klumzy_Null) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	result = Klumzy_ShutdownDisplay(&display);
	if (Klumzy_IsResultSuccess(result) == Klumzy_Null) {
		printf("Failed to shutdown display: %lu\n", GetLastError());
	}

	return Klumzy_Result_SUCCESS;
}
