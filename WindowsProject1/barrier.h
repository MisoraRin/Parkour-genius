#pragma once
#include"stdafx.h"
class barrier {
private:
	bool tag_land;//��Ǹ��ϰ��ڵ����ϻ����ڵ�����
	int height;
	float x;
	string file;
public:
	float speed;
	int height_get();
	float x_get();
	barrier(const char*p, int a, float b);//���������ֱ��ǣ��ļ�·�����߶Ⱥ�x������
	~barrier() = default;
	void flash(float t);//ˢ��λ�õĺ�����tΪʱ�䣬Ĭ�ϵ���ˢ��ʱ��
	const char* file_direction();//��ȡ�ļ�·��
};
