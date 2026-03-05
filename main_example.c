#include <windows.h>
#include <GL/gl.h>
#include <stdio.h>

#define MAX_WINDOWS 10

HWND windows[MAX_WINDOWS];
HDC hDCs[MAX_WINDOWS];
HGLRC hRCs[MAX_WINDOWS];
int windowCount = 0;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HWND CreateOpenGLWindow(const char* title, int x, int y, int width, int height, BYTE type, DWORD flags) {
	int pf;
	HDC hDC;
	HWND hWnd;
	WNDCLASS wc;
	PIXELFORMATDESCRIPTOR pfd;
	static HINSTANCE hInstance = 0;

	if (!hInstance) {
		hInstance = GetModuleHandle(NULL);
		wc.style = CS_OWNDC;
		wc.lpfnWndProc = (WNDPROC)WindowProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = hInstance;
		wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = NULL;
		wc.lpszMenuName = NULL;
		wc.lpszClassName = "OpenGL";

		if (!RegisterClass(&wc)) {
			MessageBox(NULL, "RegisterClass() failed:  Cannot register window class.", "Error", MB_OK);
			return NULL;
		}
	}

	hWnd = CreateWindow("OpenGL", title, WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
						x, y, width, height, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL) {
		MessageBox(NULL, "CreateWindow() failed:  Cannot create a window.", "Error", MB_OK);
		return NULL;
	}

	hDC = GetDC(hWnd);
	memset(&pfd, 0, sizeof(pfd));
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | flags;
	pfd.iPixelType = type;
	pfd.cColorBits = 32;

	pf = ChoosePixelFormat(hDC, &pfd);
	if (pf == 0) {
		MessageBox(NULL, "ChoosePixelFormat() failed:  Cannot find a suitable pixel format.", "Error", MB_OK);
		ReleaseDC(hWnd, hDC);
		return NULL;
	}

	if (SetPixelFormat(hDC, pf, &pfd) == FALSE) {
		MessageBox(NULL, "SetPixelFormat() failed:  Cannot set format specified.", "Error", MB_OK);
		ReleaseDC(hWnd, hDC);
		return NULL;
	}

	DescribePixelFormat(hDC, pf, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
	ReleaseDC(hWnd, hDC);

	if (windowCount < MAX_WINDOWS) {
		windows[windowCount] = hWnd;
		hDCs[windowCount] = GetDC(hWnd);
		hRCs[windowCount] = wglCreateContext(hDCs[windowCount]);
		if (windowCount > 0) {
			wglShareLists(hRCs[0], hRCs[windowCount]);
		}
		windowCount++;
	}

	return hWnd;
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2i(0, 1);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2i(-1, -1);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2i(1, -1);
	glEnd();
	glFlush();
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_PAINT: {
		int index = -1;
		for (int i = 0; i < windowCount; i++) {
			if (windows[i] == hWnd) {
				index = i;
				break;
			}
		}
		if (index >= 0) {
			wglMakeCurrent(hDCs[index], hRCs[index]);
			display();
			SwapBuffers(hDCs[index]);
		}
		PAINTSTRUCT ps;
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;
	}
	case WM_SIZE: {
		int index = -1;
		for (int i = 0; i < windowCount; i++) {
			if (windows[i] == hWnd) {
				index = i;
				break;
			}
		}
		if (index >= 0) {
			wglMakeCurrent(hDCs[index], hRCs[index]);
			glViewport(0, 0, LOWORD(lParam), HIWORD(lParam));
			InvalidateRect(hWnd, NULL, TRUE);
		}
		return 0;
	}
	case WM_CHAR:
		if (wParam == 27) {
			PostMessage(hWnd, WM_CLOSE, 0, 0);
		}
		return 0;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		return 0;
	case WM_DESTROY:
		for (int i = 0; i < windowCount; i++) {
			if (windows[i] == hWnd) {
				wglMakeCurrent(hDCs[i], hRCs[i]);
				wglDeleteContext(hRCs[i]);
				ReleaseDC(windows[i], hDCs[i]);
				for (int j = i; j < windowCount - 1; j++) {
					windows[j] = windows[j + 1];
					hDCs[j] = hDCs[j + 1];
					hRCs[j] = hRCs[j + 1];
				}
				windowCount--;
				break;
			}
		}
		if (windowCount == 0) {
			PostQuitMessage(0);
		}
		return 0;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}

int main() {
	MSG msg;

	HWND hWnd1 = CreateOpenGLWindow("OpenGL - Window 1", 50, 50, 400, 400, PFD_TYPE_RGBA, 0);
	HWND hWnd2 = CreateOpenGLWindow("OpenGL - Window 2", 500, 50, 400, 400, PFD_TYPE_RGBA, 0);

	if (!hWnd1 || !hWnd2) {
		return 1;
	}

	ShowWindow(hWnd1, SW_SHOW);
	ShowWindow(hWnd2, SW_SHOW);

	wglMakeCurrent(hDCs[0], hRCs[0]);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	for (int i = 0; i < windowCount; i++) {
		wglMakeCurrent(hDCs[i], hRCs[i]);
		wglDeleteContext(hRCs[i]);
		ReleaseDC(windows[i], hDCs[i]);
		DestroyWindow(windows[i]);
	}

	return (int)msg.wParam;
}
