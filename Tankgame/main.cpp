#include<iostream>
#include <stdio.h> 
#include <windows.h>
using namespace std;
#include"Console.h"
#include"Control.h"
#include"Map.h"
#include"Tank.h"

int main() {
	Console console;				//初始化控制台
	Map map;						//初始化地图
	map.show();						//输出地图
	Tank tank;
	tank.append(map);
	map.show();
	system("pause");
	return 0;
}