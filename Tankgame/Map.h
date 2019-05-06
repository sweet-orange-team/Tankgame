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
	static int life;			//	  数字1代表墙体，数字0代表空格，数字2代表剩余生命，数字3代表总分
	static int score;			//	在map[i][j][1]中
	int map[45][150][2];		//	  数字是多少就代表枚举颜色那里的颜色
};

#endif // !_MAP_H