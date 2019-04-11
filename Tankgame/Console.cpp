#include<iostream>										//��һҳ���Ǳ���.............�����ܵ�ͨ��������
#include<string>										//û�ҵ�����ʲô���ش��󣬷�������......
#include<cstring>										//
#include <windows.h>									//
#include <stdio.h>										//
using namespace std;
#include"Console.h"

Console::Console()
{
	system("title TankGame-by charon and Yvein");		//���ÿ���̨����
	system("mode con cols=100 lines=35");				//���ÿ�͸�
	cursorSee(false);									//��ʼ���������
}

Console::~Console()
{
}

void Console::cursorPosition(const int x, const int y)	//���ù��λ��
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void Console::cursorSee(bool flag)					//��ʾ�������ع��
{
	HANDLE h_GAME = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME, &cursor_info);
	cursor_info.bVisible = flag;
	SetConsoleCursorInfo(h_GAME, &cursor_info);
}

void Console::setColor(char flag)					//����������ɫ
{
	/*enum color
	{
		black, white, red, green, blue, yellow, pink		//����ĸ������ɫ
	};*/
	switch (flag)
	{
	case 'o':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY); break;
	case 'w':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE); break;
	case 'r':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); break;
	case 'g':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); break;
	case 'b':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE); break;
	case 'y':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN); break;
	case 'p':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_BLUE); break;
	default:												//Ĭ����ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
		break;
	}
}

void Console::color(int a) {//�ı��������ɫ����system("color x")��ö�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
	/*
	<span style="white-space:pre">	</span>��
		1	����ɫ		9	ǳ��ɫ		����
		2	����ɫ		10	ǳ��ɫ		1~15	��ɫ		128~143 	��ɫ
		3	����ɫ		11	ǳ��ɫ		16~31	����ɫ		144~159 	ǳ��ɫ
		4	���ɫ		12	ǳ��ɫ		32~47	����ɫ		160~175 	ǳ��ɫ
		5	���ɫ		13	ǳ��ɫ		48~63	����ɫ		176~191 	ǳ��ɫ
		6	��ɫ		14	ǳ��ɫ		64~79	���ɫ		192~207 	ǳ��ɫ
		7	���ɫ		15	ǳ��ɫ		80~95	���ɫ		208~223 	ǳ��ɫ
		8	��ɫ						96~111	���ɫ		224~239 	ǳ��ɫ
										112~127 ���ɫ		240~255 	ǳ��ɫ							
	*/
}

int Console::check(char c) {			//���ĳ�������Ƿ���(�����д��ĸ�������¾͸ı������ɫ
	int re = 0;							//while (1) {
	if (!KEY_DOWN(c)) {					//	if (console.check('Q')) {
		color(7);						//		cout << "��ð���" << endl;
		re = 0;							//	};
	}									//	
	else { 								//	Sleep(20);//ѭ��ʱ��������ֹ̫ռ�ڴ�
		color(112); 					//	//system("cls");//���� 
		re = 1;							//}
	}									//
	//printf("  %c  ", c);				//
	color(7);							//
	return re;							//
}

