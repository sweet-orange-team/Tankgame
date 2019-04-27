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
	Tank(int blood = 100, int armour = 0, int speed = 1, Color color = white, int direction = 0);
	~Tank();
	//void show(Console console, int direction=0, int x=40, int y=50);			//在地图上输出坦克||不行，控制台不能插入输出
	void append(Map &Map, int x = 40, int y = 50);
protected:
	const char body[4][3][6] = {
		// 上
		{
			{ 0, 0, 1, 1, 0, 0 },			//地图输出的时候一个■占了两个位置，被侵占的位置跳过输出，因此设置成这个样子
			{ 1, 1, 1, 1, 1, 1,},			//  ■
			{ 1, 1, 0, 0, 1, 1 },			//■■■
		},									//■  ■
		// 下
		{
			{ 1, 1, 0, 0, 1, 1 },
			{ 1, 1, 1, 1, 1, 1 },
			{ 0, 0, 1, 1, 0, 0 },
		},
		// 左
		{
			{ 0, 0, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 1, 1 },
		},
		// 右
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



class Tank_Users :public Tank {             //己方坦克子类
public:
	Tank_Users(int id, int blood = 100, int armour = 0, int speed = 1, Color color = white, int direction = 0);
	~Tank_Users();
	int getID();
private:
	int identification;
};



class Tank_Enemies :public Tank {             //敌方坦克子类
public:
	Tank_Enemies(int id, int blood = 100, int armour = 0, int speed = 1, Color color = white, int direction = 0);
	~Tank_Enemies();
	int getID();
private:
	int identification;
};



class Tank_Ordinary :public Tank_Enemies {             //普通敌方坦克子类
public:
	Tank_Ordinary(int id, int blood = 100, int armour = 0, int speed = 1, Color color = white, int direction = 0);
	~Tank_Ordinary();
};



class Tank_Boss :public Tank_Enemies {             //BOSS敌方坦克子类
public:
	Tank_Boss::Tank_Boss(int id, int blood = 100, int armour = 0, int speed = 1, Color color = white, int direction = 0);
	Tank_Boss::~Tank_Boss();
};

#endif // !_TANK_H