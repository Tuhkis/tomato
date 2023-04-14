#include "../tomato.h"

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include <stdio.h>

#ifdef __linux__
tm_Window tm_createWindow(int w, int h, char* title) {
	tm_Window win = {0};

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	win.win = glfwCreateWindow(w, h, title, 0, 0);
	glfwMakeContextCurrent(win.win);
	glfwSwapInterval(1);

	return win;
}
#elif __APPLE__
// WARN: Dodgy fuckery... might not even compile.
#include <Metal/Metal.h>
tm_Window tm_createWindow(int w, int h, char* title) {
	tm_Widnow win = {0};

	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	win.win *window = glfwCreateWindow(w, h, title, NULL, NULL);
	NSWindow *nswindow = glfwGetCocoaWindow(window);
	nswindow.contentView.layer = swapchain;
	nswindow.contentView.wantsLayer = YES;
	glfwMakeContextCurrent(win.win);
	glfwSwapInterval(1);

	return win;
}
#else
tm_Window tm_createWindow(int w, int h, char* title) {
	printf("tm_createWindow not implemented yet!\n");
}
#endif

int tm_windowShouldClose(tm_Window win) {
	return glfwWindowShouldClose(win.win);
}

void tm_closeWindow(tm_Window win) {
	glfwTerminate();
}

void tm_processWindow(tm_Window win) {
	glfwSwapBuffers(win.win);
        glfwPollEvents();
}

