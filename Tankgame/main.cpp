#include<iostream>
#include <stdio.h> 
#include <windows.h>
using namespace std;
#include"Console.h"
#include"Control.h"
#include"Map.h"


int main() {
	Console console;				//初始化控制台
	Map map;						//初始化地图
	map.showmap();					//输出地图
	


	system("pause");
	return 0;
}