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
	graphic(const char*p) {
		file = p;
	}
	//ͨ���ٶȡ��������ٶȺ�ʱ�������һ֡����ʾλ��
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
	//��Ծ����
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