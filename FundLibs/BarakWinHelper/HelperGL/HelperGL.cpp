#include "HelperGL.h"
#include <glad/glad.h>
#include <Windows.h>

void EnableOpenGL(hWindow w, HDC* hDC, HGLRC* hRC) {
	PIXELFORMATDESCRIPTOR pfd;
	int iFormat;

	*hDC = w.getHDC();
	ZeroMemory(&pfd, sizeof(pfd));

	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;

	iFormat = ChoosePixelFormat(*hDC, &pfd);
	SetPixelFormat(*hDC, iFormat, &pfd);
	*hRC = wglCreateContext(*hDC);
	wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL(hWindow w, HDC hDC, HGLRC hRC) {
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hRC);
	ReleaseDC(w.getWin(), hDC);
}