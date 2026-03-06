/* This file is apart of KlumzyEngine and is property of Klumzy Duk Gamez
 * Copyright (c) 2026 Klumzy Duk Gamez
 * See LICENSE.md for license details */

#include "Klumzy_Display.h"
#include <stdio.h>

#ifdef KLUMZY_SYSTEM_WINDOWS
LRESULT CALLBACK Klumzy_WindowProcedure(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam) {
	Klumzy_WindowLPPARAM* lpParam = (Klumzy_WindowLPPARAM*)GetWindowLongPtr(windowHandle, GWLP_USERDATA);

	switch (message) {
		case WM_CREATE: {
			CREATESTRUCT* createSturct = (CREATESTRUCT*)lParam;
			lpParam = (Klumzy_WindowLPPARAM*)createSturct->lpCreateParams;
			SetWindowLongPtr(windowHandle, GWLP_USERDATA, (LONG_PTR)lpParam);
		}
		case WM_PAINT: {
			if (lpParam == Klumzy_Null) {
				break;
			}
			wglMakeCurrent(lpParam->window->deviceContextHandle, lpParam->window->glContextHandle);
			glClear(GL_COLOR_BUFFER_BIT);
			glBegin(GL_TRIANGLES);
			glColor3f(1.0f, 0.5f, 1.0f);
			glVertex2i(0, 1);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex2i(-1, -1);
			glColor3f(0.2f, 1.0f, 1.0f);
			glVertex2i(1, -1);
			glEnd();
			glFlush();
			SwapBuffers(lpParam->window->deviceContextHandle);
			PAINTSTRUCT paintStruct;
			BeginPaint(lpParam->window->windowHandle, &paintStruct);
			EndPaint(lpParam->window->windowHandle, &paintStruct);
		}
		case WM_SIZE: {
			if (lpParam == Klumzy_Null) {
				break;
			}
			wglMakeCurrent(lpParam->window->deviceContextHandle, lpParam->window->glContextHandle);
			glViewport(0, 0, LOWORD(lParam), HIWORD(lParam));
			InvalidateRect(lpParam->window->windowHandle, Klumzy_Null, TRUE);
			break;
		}
		case WM_CLOSE: {
			if (lpParam == Klumzy_Null) {
				break;
			}
			Klumzy_CloseWindow((Klumzy_Display*)lpParam->display, lpParam->window);
			break;
		}
		default:
			break;
	}

	return DefWindowProc(windowHandle, message, wParam, lParam);
}
#endif /* ifdef KLUMZY_SYSTEM_WINDOWS */

Klumzy_Result Klumzy_StartupDisplay(Klumzy_Display* display) {
#ifdef KLUMZY_SYSTEM_WINDOWS
	display->windowClassName = "KlumzyEngine-WNDCLASSEX";

	display->windowClass = (WNDCLASSEX){};
	display->windowClass.cbSize = sizeof(WNDCLASSEX);
	display->windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	display->windowClass.lpfnWndProc = Klumzy_WindowProcedure;
	display->windowClass.cbClsExtra = 0;
	display->windowClass.cbWndExtra = 0;
	display->windowClass.hInstance = GetModuleHandle(Klumzy_Null);
	display->windowClass.hIcon = Klumzy_Null;
	display->windowClass.hCursor = LoadCursor(Klumzy_Null, IDC_ARROW);
	display->windowClass.hbrBackground = Klumzy_Null;
	display->windowClass.lpszMenuName = Klumzy_Null;
	display->windowClass.lpszClassName = display->windowClassName;
	display->windowClass.hIconSm = Klumzy_Null;

	if (RegisterClassEx(&display->windowClass) == Klumzy_Null) {
		return Klumzy_Result_FAILURE_REGISTER_WNDCLASSEX;
	}

	for (Klumzy_UInt32 i = 0; i < KLUMZY_DISPLAY_MAX_WINDOWS; i++) {
		display->windows[i].windowHandle = Klumzy_Null;
	}
#endif /* ifdef KLUMZY_SYSTEM_WINDOWS */
	return Klumzy_Result_SUCCESS;
}

Klumzy_Result Klumzy_ShutdownDisplay(Klumzy_Display* display) {
	for (Klumzy_UInt32 i = 0; i < KLUMZY_DISPLAY_MAX_WINDOWS; i++) {
		if (Klumzy_IsWindowOpen(display->windows[i])) {
			Klumzy_CloseWindow(display, &display->windows[i]);
		}
	}

#ifdef KLUMZY_SYSTEM_WINDOWS
	if (UnregisterClass(display->windowClassName, GetModuleHandle(Klumzy_Null)) == Klumzy_Null) {
		return Klumzy_Result_FAILURE_UNREGISTER_WNDCLASSEX;
	}
#endif /* ifdef KLUMZY_SYSTEM_WINDOWS */

	return Klumzy_Result_SUCCESS;
}

Klumzy_Result Klumzy_OpenWindow(Klumzy_Display* display, Klumzy_Window** window) {
	*window = Klumzy_Null;
	Klumzy_UInt32 i;

	for (i = 0; i < KLUMZY_DISPLAY_MAX_WINDOWS; i++) {
		if (Klumzy_IsWindowOpen(display->windows[i]) == Klumzy_Null) {
			*window = &display->windows[i];
			break;
		}
	}

	if (*window == Klumzy_Null) {
		return Klumzy_Result_ERROR_OUT_OF_WINDOWS;
	}

	Klumzy_Window* wnd = *window;

#ifdef KLUMZY_SYSTEM_WINDOWS
	display->windowLpParams[i].display = (struct Klumzy_Display*)display;
	display->windowLpParams[i].window = wnd;

	wnd->windowHandle = CreateWindowEx(
		Klumzy_Null,
		display->windowClassName,
		"KlumzyEngine",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,

		640,
		360,
		Klumzy_Null,
		Klumzy_Null,
		GetModuleHandle(Klumzy_Null),
		(Klumzy_Void*)&display->windowLpParams[i]);
	if (wnd->windowHandle == Klumzy_Null) {
		return Klumzy_Result_FAILURE_CREATE_WINDOW;
	}

	ShowWindow(wnd->windowHandle, SW_SHOW);
	UpdateWindow(wnd->windowHandle);

	wnd->deviceContextHandle = GetDC(wnd->windowHandle);

	wnd->pixelFormatDescriptor = (PIXELFORMATDESCRIPTOR){};
	wnd->pixelFormatDescriptor.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	wnd->pixelFormatDescriptor.nVersion = 1;
	wnd->pixelFormatDescriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
	wnd->pixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
	wnd->pixelFormatDescriptor.cColorBits = 32;
	wnd->pixelFormatDescriptor.cRedBits = 0;
	wnd->pixelFormatDescriptor.cRedShift = 0;
	wnd->pixelFormatDescriptor.cGreenBits = 0;
	wnd->pixelFormatDescriptor.cGreenShift = 0;
	wnd->pixelFormatDescriptor.cBlueBits = 0;
	wnd->pixelFormatDescriptor.cBlueShift = 0;
	wnd->pixelFormatDescriptor.cAlphaBits = 0;
	wnd->pixelFormatDescriptor.cAlphaShift = 0;
	wnd->pixelFormatDescriptor.cAccumBits = 0;
	wnd->pixelFormatDescriptor.cAccumRedBits = 0;
	wnd->pixelFormatDescriptor.cAccumGreenBits = 0;
	wnd->pixelFormatDescriptor.cAccumBlueBits = 0;
	wnd->pixelFormatDescriptor.cAccumAlphaBits = 0;
	wnd->pixelFormatDescriptor.cDepthBits = 32;
	wnd->pixelFormatDescriptor.cStencilBits = 0;
	wnd->pixelFormatDescriptor.cAuxBuffers = 0;
	wnd->pixelFormatDescriptor.iLayerType = PFD_MAIN_PLANE;
	wnd->pixelFormatDescriptor.bReserved = 0;
	wnd->pixelFormatDescriptor.dwLayerMask = 0;
	wnd->pixelFormatDescriptor.dwVisibleMask = 0;
	wnd->pixelFormatDescriptor.dwDamageMask = 0;

	wnd->pixelFormat = ChoosePixelFormat(wnd->deviceContextHandle, &wnd->pixelFormatDescriptor);
	if (wnd->pixelFormat == Klumzy_Null) {
		ReleaseDC(wnd->windowHandle, wnd->deviceContextHandle);
		return Klumzy_Result_FAILURE_CHOOSE_PIXEL_FORMAT;
	}

	if (SetPixelFormat(wnd->deviceContextHandle, wnd->pixelFormat, &wnd->pixelFormatDescriptor) == Klumzy_Null) {
		ReleaseDC(wnd->windowHandle, wnd->deviceContextHandle);
		return Klumzy_Result_FAILURE_SET_PIXEL_FORMAT;
	}

	DescribePixelFormat(wnd->deviceContextHandle, wnd->pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &wnd->pixelFormatDescriptor);

	wnd->glContextHandle = wglCreateContext(wnd->deviceContextHandle);
	if (wnd->glContextHandle == Klumzy_Null) {
		return Klumzy_Result_FAILURE_CREATE_GL_CONTEXT;
	}

	wglMakeCurrent(wnd->deviceContextHandle, wnd->glContextHandle);

	for (Klumzy_UInt32 i = 0; i < KLUMZY_DISPLAY_MAX_WINDOWS; i++) {
		if (Klumzy_IsWindowOpen(display->windows[i])) {
			if (display->windows[i].windowHandle == wnd->windowHandle) {
				break;
			}

			if (wglShareLists(display->windows[i].glContextHandle, wnd->glContextHandle) == Klumzy_Null) {
				printf("Failed wglShareLists: %d\n", i);
				return Klumzy_Result_FAILURE_SHARE_GL_LISTS;
			}
		}
	}

	InvalidateRect(wnd->windowHandle, Klumzy_Null, TRUE);
	UpdateWindow(wnd->windowHandle);

#endif /* ifdef KLUMZY_SYSTEM_WINDOWS */
	return Klumzy_Result_SUCCESS;
}

Klumzy_Bool Klumzy_IsWindowOpen(Klumzy_Window window) {
#ifdef KLUMZY_SYSTEM_WINDOWS
	if (window.windowHandle == Klumzy_Null) {
		return Klumzy_False;
	}
#endif /* ifdef KLUMZY_SYSTEM_WINDOWS */
	return Klumzy_True;
}

Klumzy_Result Klumzy_CloseWindow(Klumzy_Display* display, Klumzy_Window* window) {
#ifdef KLUMZY_SYSTEM_WINDOWS
	wglMakeCurrent(window->deviceContextHandle, window->glContextHandle);
	wglDeleteContext(window->glContextHandle);
	ReleaseDC(window->windowHandle, window->deviceContextHandle);
	if (DestroyWindow(window->windowHandle) == Klumzy_Null) {
		return Klumzy_Result_FAILURE_DESTROY_WINDOW;
	}
	window->windowHandle = Klumzy_Null;
#endif /* ifdef KLUMZY_SYSTEM_WINDOWS */

	Klumzy_Bool closed = Klumzy_True;
	for (Klumzy_UInt32 i = 0; i < KLUMZY_DISPLAY_MAX_WINDOWS; i++) {
		if (Klumzy_IsWindowOpen(display->windows[i])) {
			closed = Klumzy_False;
			break;
		}
	}

	if (closed) {
#ifdef KLUMZY_SYSTEM_WINDOWS
		PostQuitMessage(0);
#endif /* #ifdef KLUMZY_SYSTEM_WINDOWS */
	}

	return Klumzy_Result_SUCCESS;
}
