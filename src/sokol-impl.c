// Held together by... I don't even know...
#define SOKOL_IMPL
#define GLFW_INCLUDE_NONE
#ifdef __APPLE__
#define SOKOL_METAL
#define GLFW_EXPOSE_NATIVE_COCOA
#elif __linux__
#define SOKOL_GLCORE33
#elif _WIN64
#define SOKOL_D3D11
#else
#define SOKOL_GLES2
#endif

#include "../sokol/sokol_gfx.h"
#include "../sokol/sokol_log.h"

