#include"function.h"


void Function::paintpic(HDC hdc) 
{
	BitBlt(hdc, 0, 0, 698, 500, mdc, 0,0, SRCCOPY);//�����ڱ�����ͼ
}
void Function::show() 
{

}
