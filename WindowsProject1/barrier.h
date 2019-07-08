#pragma once
#include"stdafx.h"
class barrier {
private:
	bool tag_land;
	int height;
	float x;
	string file;
public:
	float speed;
	int height_get() {
		return height;
	}
	float x_get() {
		return x;
	}
	barrier(const char*p,int a,float b) {
		file = p;
		height = a;
		x = b;
	}
	~barrier() = default;
	void flash(float t=time_interval) {
		x = x - speed*t;
	}
	const char* file_direction() {
		const char*p = file.c_str();
		return p;
	}
};
