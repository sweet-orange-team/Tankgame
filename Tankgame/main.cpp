#include"Console.h"
#include"Control.h"
#include"Map.h"
#include"Tank.h"

int main() {
	Console console;				//初始化控制台
	Map map;						//初始化地图
    Tank tank;
	map.show();						//输出地图	Tank tank(100, 0, 1, yellow);	//新建一个基类坦克
	tank.append(map);				//添加坦克进地图--不能直接输出
	map.show();

	system("pause");
	return 0;
}