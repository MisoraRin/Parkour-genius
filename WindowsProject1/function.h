#pragma once
#include"stdafx.h"
#include <iostream>
#include<string>
extern HINSTANCE hInstance;
extern HWND hwnd;
extern HDC mdc;
static HWND hLabUsername;  //��̬�ı���--�û���
static HWND hEditUsername; //�����ı������
static HWND hBtnLogin;     //��ʼ��ť
static HFONT hFont;        //�߼�����

#define IDB_ONE     3301  //��ť1
#define IDB_TWO     3302  //��ť2
#define IDB_THREE   3303  //��ť3
#define IDB_FOUR    3304  //��ť4
#define IDB_FIVE    3305  //��ť5
#define IDB_SIX     3306  //��ť6

class Function {
private:
	const int x1 = 10; //��Ϸ���ݵ�ʹ��
	const int x2=10;
	int y1, y2;
public:
	
	void paintpic(HDC hdc);//���汳��ͼƬ����
	void show();//��Ϸ�������
	//Function(int d1, int d2);//���캯����ֵ
	//~Function();//��������
};
