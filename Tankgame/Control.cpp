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


int Control::start() {				//主程序开始
	Console console;				//初始化控制台
	Map map;						//初始化地图
	map.show();
	Tank mytank = Tank();
	TankEnemy enemies = TankEnemy();
	enemies.show();
	mytank.show();
	while (true)
	{
		console.checkKey(mytank);
		mytank.bulletMove();
		map.refresh();
 		enemies.move();
		map.refresh();
		if (!mytank.isAlive())break;
		Sleep(100);
		}

	system("pause");
	system("cls");
	system("pause");
	return 0;
}

