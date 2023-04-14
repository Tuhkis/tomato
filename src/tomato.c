#include <stdio.h>

#include "../tomato.h"

#include "../sokol/sokol_gfx.h"
#include "../sokol/sokol_log.h"

sg_pass_action passAction;

int tm_init() {
	sg_setup(&(sg_desc){
		.logger.func = slog_func,
	});
	return 1;
}

void tm_beginDraw(tm_Window win) {
	passAction = (sg_pass_action) {
		.colors[0] = { .action = SG_ACTION_CLEAR, .value = { 1.0f, 0.0f, 0.0f, 1.0f } }
	};

	int curWidth, curHeight;
        glfwGetFramebufferSize(win.win, &curWidth, &curHeight);
        sg_begin_default_pass(&passAction, curWidth, curHeight);
}

void tm_endDraw(tm_Window win) {
	sg_end_pass();
        sg_commit();
	tm_processWindow(win);
}

