// WindowsProject1.cpp : 定义应用程序的入口点。

#include "WindowsProject1.h"
#include <tchar.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include"function.h"
#include"graphic.h"
#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 300

using namespace std;
const char g_szClassName[] = "myWindowClass";
HINSTANCE hInstance;
HINSTANCE hinst;
HBITMAP hbmp;//声明一个位图对象
PAINTSTRUCT ps;
HDC mdc;//再建立一个与hdc兼容的内存DC(mdc)
HDC hdc;//声明获取窗口DC(hdc)
WNDCLASSEX wc;
MSG Msg;
HWND hwnd;
Function paint;
Function Data;





LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lparam)//主窗口过程
{
	
	HDC hdcStatic;
	static HFONT hFont;  //逻辑字体
	static HWND hStatic;  //静态文本框控件
	static HBRUSH hBrush;  //画刷

	switch (msg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		paint.paintpic(hdc);
		EndPaint(hwnd, &ps);
		break;
	case WM_CREATE:
	{
		CreateWindowEx(0, "Button", "Begin", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			0, 10, 100, 40, hwnd, (HMENU)IDB_ONE, hInstance, NULL);

		CreateWindowEx(0, "Button", "Game Rule", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			0, 60, 100, 40, hwnd, (HMENU)IDB_THREE, hInstance, NULL);
		//创建画刷
		hBrush = CreateSolidBrush(RGB(0x41, 0x96, 0x4F));
		//创建逻辑字体
		hFont = CreateFont(-40/*高*/, -20/*宽*/, 0, 0, 700 /*700表示粗体*/,
			FALSE/*斜体?*/, FALSE/*下划线?*/, FALSE/*删除线?*/, DEFAULT_CHARSET,
			OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
			FF_DONTCARE, TEXT("微软雅黑")
		);
		//创建静态文本框控件
		hStatic = CreateWindow(TEXT("static"), TEXT("欢迎来到你的世界！"),
			WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
			0 /*x坐标*/, 0 /*y坐标*/, 2000 /*宽度*/, 1200 /*高度*/,
			hwnd /*父窗口句柄*/, (HMENU)1 /*控件ID*/, hinst /*当前程序实例句柄*/, NULL
		);
		//设置控件的字体
		SendMessage(hStatic, WM_SETFONT, (WPARAM)hFont, NULL);
		break;
	case WM_CTLCOLORSTATIC:
		hdcStatic = (HDC)wParam;
		SetTextColor(hdcStatic, RGB(255, 255, 255));  //白色
		SetBkColor(hdcStatic, RGB(0x41, 0x96, 0x4F));  //翠绿色
		return (INT_PTR)hBrush;
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDB_ONE:
			//Game()运行游戏
			break;
		case IDB_TWO:
			//show()游戏规则展示
			break;
		case IDB_THREE:
		//endgame()
			break;
		default:
			break;
		}
		break;

	case WM_DESTROY:
		DeleteDC(mdc);
		DeleteObject(hbmp);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lparam);// pass 给系统，咱不管
	}
	return 0;
}
ATOM RegisterMyWindow(HINSTANCE hInstance)
{
	// 1)配置窗口属性
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc; // 设置第四步的窗口过程回调函数
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// 2)注册
	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, TEXT("窗口注册失败!"), TEXT("错误"), MB_ICONEXCLAMATION | MB_OK);
		exit(0); // 进程退出
	}
	return RegisterClassEx(&wc);
}
BOOL CreateMyWindow(HINSTANCE hInstance, int nCmdShow)
{

	hinst = hInstance;

	hwnd = CreateWindow(
		g_szClassName,
		TEXT("一个神奇的窗口"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,// 出现坐标 x,y 默认分配 窗口宽 400 高 300
		NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
	{
		MessageBox(NULL, TEXT("窗口创建失败!"), TEXT("错误"), MB_ICONEXCLAMATION | MB_OK);
		exit(0); // 进程退出
	}

	// 显示窗口
	MoveWindow(hwnd, 10, 10, 698, 500, true);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	hdc = GetDC(hwnd);
	mdc = CreateCompatibleDC(hdc);//获取窗口DC(hdc)再建立一个与hdc兼容的内存DC(mdc)
	hbmp = (HBITMAP)LoadImage(NULL, "D:\\Desktop\\pic\\888.bmp ", IMAGE_BITMAP, 698, 500
		, LR_LOADFROMFILE);//加载文件名为888.bmp的位图到hbmp

	if (SelectObject(mdc, hbmp))//将hbmp存到内存DC(mdc)中去
		paint.paintpic(hdc);//调用Paintpic()函数
	ReleaseDC(hwnd, hdc);
	return TRUE;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	graphic g;
	RegisterMyWindow(hInstance);

	if (!CreateMyWindow(hInstance, nCmdShow)) {
		return 0;
	}


	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}
