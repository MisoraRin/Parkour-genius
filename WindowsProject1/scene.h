#pragma once
#include"graphic.h"
#include"barrier.h"
#include"stdafx.h"
class scene{
private:
	float time;//����ϵͳʱ�䣬���ڼ����ܹ���·�̺���Ϸѭ����ʱ
	float time_pre;
	float time_now;//���������ж�ˢ��ʱ��ı���
public:
	bool time_flash();
	bool draw_graphic(graphic&g);
};