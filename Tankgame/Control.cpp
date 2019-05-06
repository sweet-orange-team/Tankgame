#include<iostream>	
using namespace std;
#include"Control.h"
#include"Map.h"
#include"Console.h"
#include"Tank.h"


Control::Control(int _flag)
{
	flag = _flag;
}

Control::~Control()
{
}


int Control::start() {				//主程序开始
	Console console;				//初始化控制台
	Map map;						//初始化地图
	Tank tank(100,0,1,yellow,0);
	//map.show();						//输出地图	Tank tank(100, 0, 1, yellow);	//新建一个基类坦克
	tank.append(map);				//添加坦克进地图--不能直接输出
	while (true)
	{
		map.show();
	}
	

	system("pause");
	return 0;
}
