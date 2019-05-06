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


int Control::start() {				//主程序开始
	Console console;				//初始化控制台
	Map map;						//初始化地图
	map.show();
	console.setCursorPosition(7, 90);
	console.setColor(red);
	cout << "Game Start!";


	system("pause");
	return 0;
}
