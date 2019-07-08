#pragma once
#include"stdafx.h"
#include <iostream>
#include<string>
extern HINSTANCE hInstance;
extern HWND hwnd;
extern HDC mdc;
static HWND hLabUsername;  //静态文本框--用户名
static HWND hEditUsername; //单行文本输入框
static HWND hBtnLogin;     //开始按钮
static HFONT hFont;        //逻辑字体

#define IDB_ONE     3301  //按钮1
#define IDB_TWO     3302  //按钮2
#define IDB_THREE   3303  //按钮3
#define IDB_FOUR    3304  //按钮4
#define IDB_FIVE    3305  //按钮5
#define IDB_SIX     3306  //按钮6

class Function {
private:
	const int x1 = 10; //游戏数据的使用
	const int x2=10;
	int y1, y2;
public:
	
	void paintpic(HDC hdc);//界面背景图片设置
	void show();//游戏规则介绍
	//Function(int d1, int d2);//构造函数赋值
	//~Function();//析构函数
};
