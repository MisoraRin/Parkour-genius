#pragma once
#include"stdafx.h"
class barrier {
private:
	bool tag_land;//标记该障碍在地面上或是在地面下
	int height;
	float x;
	string file;
public:
	float speed;
	int height_get();
	float x_get();
	barrier(const char*p, int a, float b);//三个参数分别是：文件路径、高度和x轴坐标
	~barrier() = default;
	void flash(float t);//刷新位置的函数，t为时间，默认等于刷新时间
	const char* file_direction();//获取文件路径
};
