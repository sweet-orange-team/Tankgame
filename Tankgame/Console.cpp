#include<iostream>										//��һҳ���Ǳ���.............�����ܵ�ͨ��������										//
#include <windows.h>									//									//
using namespace std;
#include"Console.h"

Console::Console()
{
	system("title TankGame-by charon and Yvein");		//���ÿ���̨����
	system("mode con cols=160 lines=50");				//���ó�160�Ϳ�45
	setCursorSee(false);								//��ʼ���������
	//system("chcp 65001");								//����֧��unicode--���utf-8�ַ�ʱ������ᱨ��
}

Console::~Console()
{
}

void Console::setCursorPosition(const int x, const int y)	//���ù��λ��
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
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
	*/
}

int Console::checkKey(char key) {			//���ĳ�������Ƿ���(�����д��ĸ�������¾͸ı������ɫ
	int re = 0;							//		while (1) {
	if (!KEY_DOWN(key)) {					//			if (console.check('Q')) {
		setColor(7);						//				cout << "��ð���" << endl;
		re = 0;							//			};
	}									//			
	else { 								//			Sleep(20);//ѭ��ʱ��������ֹ̫ռ�ڴ�
		setColor(112); 					//			//system("cls");//���� 
		re = 1;							//		}
	}									//
	//printf("  %c  ", c);				//
	setColor(7);							//
	return re;							//
}

char* Console::U2G(char* utf8)			//���ɵ�uft-8��ת����
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1]; memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1]; memset(str, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr; return str;
}