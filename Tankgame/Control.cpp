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
	console.setColor(red);
	cout << "Game Start!";
	console.setColor(black);
	
}

Control::~Control()
{
}


int Control::start() {				//������ʼ
	Console console;				//��ʼ������̨
	Map map;						//��ʼ����ͼ
	map.show();
	Tank mytank = Tank();
	console.checkKey(mytank);

	cout << "check����" << endl;
	system("pause");
	return 0;
}
