#pragma once
#include"Barrier.h"
#ifndef _MAP_H
#define _MAP_H
class Map
{
public:							//30*106
	Map();						//map[][][]说明：
	~Map();						//前两个维度定坐标，第三个维度定颜色
	void show();				//0:空格, 1:墙体,     2:己方坦克,
	void refresh(barries b);	//3:子弹, 4:敌方坦克, 5:道具,
	static int map[30][106][2]; //6:河流, 7:砖块
private:
	int privateMap[30][106][2];	//用来查看地图信息
};

#endif // !_MAP_H
