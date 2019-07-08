#pragma once
#include"graphic.h"
#include"barrier.h"
#include"stdafx.h"
class scene{
private:
	float time;//保存系统时间，用于计算跑过的路程和游戏循环计时
	float time_pre;
	float time_now;//两个用于判断刷新时间的变量
public:
	bool time_flash();
	bool draw_graphic(graphic&g);
};