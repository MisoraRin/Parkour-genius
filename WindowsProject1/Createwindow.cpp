#include"Createwindow.h"
void CreateWin::createwins() 
{
	//纯虚的虚函数的空定义
}
void CreateWin::hidewin()
{
	//纯虚函数的空定义
}
void MenuWin::createwins()
{
	
}
void MenuWin::hidewin()
{
	hwnd = GetForegroundWindow();//获取最前端的窗口的句柄
	ShowWindow(hwnd, 0);//隐藏最前端的窗口
}
void MenuWin::namewin()
{
	

}
void GameWin::createwins()
{

	
}