#pragma once
#include"stdafx.h"
class graphic {
private:
	float y;
	float speed;//由于将人物设为基准点，这个速度仅为竖直方向分量
	bool tag_land, tag_jump;//两个标记，判断是否在地面上和是否在空中且能否进行二段跳
	std::string file;//对应图片保存地址
public:
	static float acceleration;//所有对象公有的重力加速度
	graphic(const char*p) {
		file = p;
	}
	//通过速度、重力加速度和时间计算下一帧的显示位置
	void flash(float t=time_interval) {
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
	float y_get() {
		return y;
	}
	//跳跃函数
	void jump() {
		if(tag_land == TRUE) {
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
	void tranverse(){
		y = -y;
	}
	~graphic() = default;
	const char* file_direction() {
		const char*p = file.c_str();
		return p;
	}
};