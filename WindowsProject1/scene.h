#pragma once

#include"stdafx.h"
class scene{
private:
	float time;//����ϵͳʱ�䣬���ڼ����ܹ���·�̺���Ϸѭ����ʱ
	float time_pre;
	float time_now;//���������ж�ˢ��ʱ��ı���
public:
	bool time_flash();
	void draw();
};