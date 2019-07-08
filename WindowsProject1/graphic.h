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
	graphic(const char*p="a");
	//通过速度、重力加速度和时间计算下一帧的显示位置
	void flash(float t);
	float y_get();
	//跳跃函数
	void jump();
	void tranverse();
	~graphic() = default;
	const char* file_direction();
};