#include "../tomato.h"

int main() {
	tm_init();
	tm_Window win = tm_createWindow(1024, 600, "Gmae windpw");
	while (!tm_windowShouldClose(win)) {
		tm_beginDraw(win);
		tm_endDraw(win);
	}
	tm_closeWindow(win);
	return 0;
}
