#include<iostream>	
using namespace std;
#include"Control.h"
#include"Map.h"
#include"Console.h"
#include"Tank.h"


Control::Control(int _flag)
{
	Console console;
	console.setCursorPosition(1, 20);
}

Control::~Control()
{
}


int Control::start() {				//������ʼ
	Console console;				//��ʼ������̨
	Map map;						//��ʼ����ͼ
	map.show();
	Tank mytank = Tank();
	TankEnemy enemies = TankEnemy();
	enemies.show();
	mytank.show();
	while (true)
	{
		console.checkKey(mytank);
		mytank.bulletMove();
 		enemies.move();
		map.refresh();
		Sleep(100);
	}

	system("pause");
	system("cls");


	system("pause");
	return 0;
}


//-----------------------------------------------------------------test
//char data[30][110];
//while (1)
//{
//	int i, j;
//	for (i = 0; i < 30; i++)
//	{
//		char*  a = "��";
//		data[i][0] = a[0];
//		data[i][1] = a[1];
//	}
//	for (i = 0; i < 30; i++)
//	{
//		console.coord.Y = i;
//		WriteConsoleOutputCharacterA(console.hOutBuf, data[i], 110, console.coord, &console.bytes);
//	}
//	//�����µĻ�����Ϊ���ʾ����
//	SetConsoleActiveScreenBuffer(console.hOutBuf);
//	Sleep(150);
//	for (i = 0; i < 30; i++)
//	{
//		for (j = 0; j < 110; j++)
//		{
//			data[i][j] = '*';
//		}
//		char*  a = Console::U2G(u8"��");
//		data[i][0] = a[0];
//		data[i][1] = a[1];
//
//
//	}
//
//
//
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < 15; j++) {
//			data[i][j] = '?';
//		}
//	}
//	for (i = 0; i < 30; i++)
//	{
//		console.coord.Y = i;
//		WriteConsoleOutputCharacterA(console.hOutput, data[i], 110, console.coord, &console.bytes);
//	}
//	//�����µĻ�����Ϊ���ʾ����
//	SetConsoleActiveScreenBuffer(console.hOutput);
//	Sleep(150);
//}