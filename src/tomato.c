#include <stdio.h>

#include "../sokol/sokol_gfx.h"
#include "../sokol/sokol_log.h"

void tm_test() {
	printf("TOMATO TSET\n");
	return;
}

int tm_init() {
	sg_setup(&(sg_desc){
		.logger.func = slog_func,
	});
	return 1;

}
