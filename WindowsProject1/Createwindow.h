#pragma once
#include"stdafx.h"
#include"function.h"
extern HINSTANCE hInstance;
extern HINSTANCE hinst;
extern HWND hwnd;


class CreateWin {
public:
	void hidewin();//隐藏窗口
    void createwins();//建立窗口
	//createwin();//构造函数
	//~creaewin();//析构函数
};
class MenuWin :public CreateWin 
{
public:
	
	 void hidewin();//隐藏窗口//不加virtual也可以
	 void createwins();//菜单的建立窗口//不加virtual也可以
	 void namewin();//名称输入窗口
	 //Menwin();//构造函数
	//~Menwin();//析构函数
};
class GameWin :public CreateWin 
{
	public:
	//void hidewin();//隐藏窗口//不加virtual也可以
	void createwins();//游戏的建立窗口//不加virtual也可以
	//void countpointWin();//游戏的计分窗口
	//void storedateWin();//退出游戏及是否保存游戏的进度的窗口
	//Gamewin();//构造函数
   //~Gamewin();//析构函数
};
