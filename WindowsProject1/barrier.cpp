#include"stdafx.h"
#include"barrier.h"
int barrier::height_get() {
	return height;
}
float barrier::x_get() {
	return x;
}
barrier::barrier(const char*p="a", int a=0, float b=0) {
	file = p;
	height = a;
	x = b;
}
void barrier::flash(float t = time_interval) {
	x = x - speed * t;
}
const char* barrier::file_direction() {
	const char*p = file.c_str();
	return p;
}