/* This file is apart of KlumzyEngine and is property of Klumzy Duk Gamez
 * Copyright (c) 2026 Klumzy Duk Gamez
 * See LICENSE.md for license details */

#ifndef __KLUMZY_DISPLAY_H__
#define __KLUMZY_DISPLAY_H__

#include "Klumzy_Common.h"
#include "Klumzy_Result.h"

#ifdef KLUMZY_SYSTEM_WINDOWS
#include <windows.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

typedef struct {
#ifdef KLUMZY_SYSTEM_WINDOWS
	HWND windowHandle;
#endif
} Klumzy_Window;

#ifndef KLUMZY_DISPLAY_MAX_WINDOWS
#define KLUMZY_DISPLAY_MAX_WINDOWS 16
#endif /* ifndef KLUMZY_DISPLAY_MAX_WINDOWS */

struct Klumzy_Display;

typedef struct {

} Klumzy_WindowInterface;

#ifdef KLUMZY_SYSTEM_WINDOWS
typedef struct {
	struct Klumzy_Display* display;
	Klumzy_Window* window;
} Klumzy_WindowLPPARAM;
#endif /* ifdef KLUMZY_SYSTEM_WINDOWS */

typedef struct {
#ifdef KLUMZY_SYSTEM_WINDOWS
	WNDCLASSEX windowClass;
	const Klumzy_Char* windowClassName;
	Klumzy_WindowLPPARAM windowLpParams[KLUMZY_DISPLAY_MAX_WINDOWS];
#endif /* ifdef KLUMZY_SYSTEM_WINDOWS */
	Klumzy_Window windows[KLUMZY_DISPLAY_MAX_WINDOWS];
	Klumzy_Bool quit;
} Klumzy_Display;

KLUMZY_DLL Klumzy_Result Klumzy_StartupDisplay(Klumzy_Display* display);
KLUMZY_DLL Klumzy_Result Klumzy_ShutdownDisplay(Klumzy_Display* display);

KLUMZY_DLL Klumzy_Result Klumzy_OpenWindow(Klumzy_Display* display, Klumzy_Window** window);
KLUMZY_DLL Klumzy_Bool Klumzy_IsWindowOpen(Klumzy_Window window);
KLUMZY_DLL Klumzy_Result Klumzy_CloseWindow(Klumzy_Display* display, Klumzy_Window* window);

#ifdef __cplusplus
} /* extern "C" */
#endif /* ifdef __cplusplus */

#endif /* __KLUMZY_DISPLAY_H__ */
