#pragma once
#include"stdafx.h"
class graphic {
private:
	float y;
	float speed;//���ڽ�������Ϊ��׼�㣬����ٶȽ�Ϊ��ֱ�������
	bool tag_land, tag_jump;//������ǣ��ж��Ƿ��ڵ����Ϻ��Ƿ��ڿ������ܷ���ж�����
	std::string file;//��ӦͼƬ�����ַ
public:
	static float acceleration;//���ж����е��������ٶ�
	graphic(const char*p="a");
	//ͨ���ٶȡ��������ٶȺ�ʱ�������һ֡����ʾλ��
	void flash(float t);
	float y_get();
	//��Ծ����
	void jump();
	void tranverse();
	~graphic() = default;
	const char* file_direction();
};