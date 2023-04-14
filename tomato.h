#pragma once

#include <GLFW/glfw3.h>
#include "./sokol/sokol_gfx.h"
#include "./sokol/sokol_log.h"

typedef struct {
	GLFWwindow* win;
} tm_Window;

tm_Window tm_createWindow(int w, int h, char* title);

