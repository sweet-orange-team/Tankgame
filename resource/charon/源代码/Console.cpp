#include<iostream>										//��һҳ���Ǳ���.............�����ܵ�ͨ��������										//
#include <windows.h>
using namespace std;
#include"Console.h"

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

Console::Console()
{
	system("title TankGame-by charon and Yvein");		//���ÿ���̨����
	setCursorSee(false);								//��ʼ���������
}

Console::~Console()
{
}

void Console::setCursorPosition(const int x, const int y)	//���ù��λ��,����x������y
{
	COORD position;
	position.X = y;
	position.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void Console::setCursorSee(bool flag)					//��ʾ�������ع��
{
	HANDLE h_GAME = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME, &cursor_info);
	cursor_info.bVisible = flag;
	SetConsoleCursorInfo(h_GAME, &cursor_info);
}


void Console::setColor(int number) {					//�ı��������ɫ����system("color x")��ö�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), number);
	/*	��������ֵ���ɫ						������ñ�����ɫ
	��
		1	����ɫ		9	ǳ��ɫ	||||	����
		2	����ɫ		10	ǳ��ɫ	||||	1~15	��ɫ		128~143 	��ɫ
		3	����ɫ		11	ǳ��ɫ	||||	16~31	����ɫ		144~159 	ǳ��ɫ
		4	���ɫ		12	ǳ��ɫ	||||	32~47	����ɫ		160~175 	ǳ��ɫ
		5	���ɫ		13	ǳ��ɫ	||||	48~63	����ɫ		176~191 	ǳ��ɫ
		6	��ɫ		14	ǳ��ɫ	||||	64~79	���ɫ		192~207 	ǳ��ɫ
		7	���ɫ		15	ǳ��ɫ	||||	80~95	���ɫ		208~223 	ǳ��ɫ
		8	��ɫ					||||	96~111	���ɫ		224~239 	ǳ��ɫ
									||||	112~127 ���ɫ		240~255 	ǳ��ɫ
		15��Ĭ��������ɫ��Ĭ�ϱ����Ǻ�ɫ
	*/
}

void Console::checkKey(TankUser &mytank) {			//���ĳ�������Ƿ���(�����д��ĸ�������¾͸ı������ɫ
		if (KEY_DOWN('W')) {
			mytank.move(0);
		}else 
		if (KEY_DOWN('S')) {
			mytank.move(1);
		}else 
		if (KEY_DOWN('A')) {
			mytank.move(2);
		}else 
		if (KEY_DOWN('D')) {
			mytank.move(3);
		}else 
		if (KEY_DOWN(' ')) {
			mytank.shoot();
		}
		else
		{
			if (KEY_DOWN('P')) {
				Console::setCursorPosition(28, 90);
				system("pause");
				Console::setCursorPosition(28, 90);
				cout << "                     ";
			}
		}
}

int Console::Random(int a, int b)		//����һ��[a,b)�ϵ�����
{
	int c = (rand() % (a - b)) + a;
	return c;
}

char* Console::U2G(char* utf8)			//���ɵ�UTF-8ת����
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1]; memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}