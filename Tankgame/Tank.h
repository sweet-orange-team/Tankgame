#pragma once
#ifndef _TANK_H
#define _TANK_H

#include<iostream>
using namespace std;
#include"Console.h"
#include"Map.h"
enum Color {					//枚举颜色变量
	yellow, gray, white, pink, red
};
class Tank						//坦克基类
{
public:
	Tank(Color color = yellow, int direction = 0, int blood = 100, int speed = 1, int armour = 50);
	~Tank();
	//void show(Console console, int direction=0, int x=40, int y=50);			//在地图上输出坦克||不行，控制台不能插入输出
	void append(Map &Map, int x = 40, int y = 50);
protected:
	const char body[4][3][6] = {
		// UP
		{
			{ 0, 0, 1, 1, 0, 0 },
			{ 1, 1, 1, 1, 1, 1,},
			{ 1, 1, 0, 0, 1, 1 },
		},
		// DOWN
		{
			{ 1, 1, 0, 0, 1, 1 },
			{ 1, 1, 1, 1, 1, 1 },
			{ 0, 0, 1, 1, 0, 0 },
		},
		// LEFT
		{
			{ 0, 0, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 0, 0 },
			{ 0, 1, 1, 1, 1, 1 },
		},
		// RIGHT
		{
			{ 1, 1, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 0, 0 },
		}
	};
	Color color;
	int direction;
	int blood;
	int speed;
	int armour;
};

#endif // !_TANK_H

