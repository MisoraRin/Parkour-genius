#include"scene.h"

bool scene::time_flash() {
	time_now = GetTickCount();
	if (time_now - time_pre > flash_speed)time_pre = time_now;
	return TRUE;
}
//bool scene::draw_graphic(graphic&g) {
//
//}