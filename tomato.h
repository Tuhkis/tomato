#pragma once

#include <GLFW/glfw3.h>
#include "./sokol/sokol_gfx.h"
#include "./sokol/sokol_log.h"

typedef struct {
	GLFWwindow* win;
} tm_Window;

tm_Window tm_createWindow(int w, int h, char* title);
int tm_windowShouldClose(tm_Window win);
void tm_closeWindow(tm_Window win);
void tm_processWindow(tm_Window win);

int tm_init();
void tm_beginDraw(tm_Window win);
void tm_endDraw(tm_Window win);
