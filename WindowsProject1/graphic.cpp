#include"stdafx.h"
#include"graphic.h"
float graphic::acceleration = 10;
void graphic::jump() {
	if (tag_land == TRUE) {
		speed = jump_speed;
		acceleration = gravity;
		tag_land = FALSE;
		tag_jump = TRUE;
	}
	if (tag_jump == TRUE) {
		speed = jump_speed;
		tag_jump = FALSE;
	}
}
void graphic::tranverse() {
	y = -y;
}
const char* graphic::file_direction() {
	const char*p = file.c_str();
	return p;
}
void graphic::flash(float t = time_interval) {
	if (tag_land == FALSE) {
		y = y + (1 / 2 * acceleration*acceleration) *t + speed * t;
		speed = speed + acceleration * t;
	}
	if (y <= datum_line) {
		acceleration = 0;
		speed = 0;
		y = 0;
		tag_land = tag_jump = TRUE;
	}
}
graphic::graphic(const char*p) {
	file = p;
}
float graphic::y_get() {
	return y;
}