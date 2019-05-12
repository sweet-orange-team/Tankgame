#pragma once
#ifndef _MAP_H
#define _MAP_H
class Map
{
public:
	static int handle;
	Map();						//map[][][]说明：
	~Map();						//	前两个维度定坐标，第三个维度定颜色
	void show();				//	在map[i][j][0]中
	static int life;			//	  1:墙体，0:空格,2:坦克,3:子弹,4:道具
	static int score;			//	在map[i][j][1]中
	int map[30][106][2];		//	  数字是多少就代表枚举颜色那里的颜色
};

#endif // !_MAP_H