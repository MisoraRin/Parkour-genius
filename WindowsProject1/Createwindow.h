#pragma once
#include"stdafx.h"
#include"function.h"
extern HINSTANCE hInstance;
extern HINSTANCE hinst;
extern HWND hwnd;


class CreateWin {
public:
	void hidewin();//���ش���
    void createwins();//��������
	//createwin();//���캯��
	//~creaewin();//��������
};
class MenuWin :public CreateWin 
{
public:
	
	 void hidewin();//���ش���//����virtualҲ����
	 void createwins();//�˵��Ľ�������//����virtualҲ����
	 void namewin();//�������봰��
	 //Menwin();//���캯��
	//~Menwin();//��������
};
class GameWin :public CreateWin 
{
	public:
	//void hidewin();//���ش���//����virtualҲ����
	void createwins();//��Ϸ�Ľ�������//����virtualҲ����
	//void countpointWin();//��Ϸ�ļƷִ���
	//void storedateWin();//�˳���Ϸ���Ƿ񱣴���Ϸ�Ľ��ȵĴ���
	//Gamewin();//���캯��
   //~Gamewin();//��������
};
