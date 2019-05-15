#pragma once
#ifndef _TANK_H
#define _TANK_H

#include<iostream>
#include"Map.h"
#include"Bullet.h"
using namespace std;

enum Color {					//枚举颜色变量
	yellow = 6, gray = 7, white = 15, pink = 12, red = 4, black = 15, green = 2
};

class Tank						//坦克基类
{
public:
	Tank(int x=20,int y=50,Color color = yellow, int direction = 0);
	~Tank();
	static int blood;
	static int score;
	void append();						//添加进地图
	void move(int direction);           //移动坦克
	void show();
	void clear();
	void shoot();
	void bulletMove();
	int isAlive();
	int getDir();								 //返回方向
	int getX();
	int getY();
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
protected:
	Color color;
	int direction;
	int speed;
	int armour;
	int x, y;                     //x,y取九宫格中点
	char* n = u8"■";
	Bullet *bullet1;
	Bullet *bullet2;
	Bullet *bullet3;
	Bullet *bullet4;
	Bullet *bullet5;
	int bulletNum=0;
};

class TankEnemy:public Tank
{
public:
	TankEnemy(int x = 4, int y = 50, Color color = pink, int direction = 1,int score=5);
	~TankEnemy();
	void move();
	void append();
	int isAlive();
private:
	int Alive = 1;
	int score;
};



class Tank_Enemies                                                                                                   //敌方坦克类
{
public:
	Tank_Enemies();
	~Tank_Enemies();
	void allEnemyMove();
	void del();
	void add();
private:
	TankEnemy* enemy1;
	TankEnemy* enemy2;
	TankEnemy* enemy3;
	TankEnemy* enemy4;
	TankEnemy* enemy5;
	int enemyNum = 0;
};

class Tank_Users {

};
//
//
//
//class Tank_Ordinary :public Tank_Enemies                                                                                          //普通敌方坦克子类
//{
//public:
//	Tank_Ordinary(Map &map, int id, int blood = 100, int armour = 0, int speed = 1, Color color = white, int direction = 0);
//	~Tank_Ordinary();
//};
//
//
//
//class Tank_Boss :public Tank_Enemies                                                                                              //BOSS敌方坦克子类
//{
//public:
//	Tank_Boss::Tank_Boss(Map &map, int id, int blood = 100, int armour = 0, int speed = 1, Color color = white, int direction = 0);
//	Tank_Boss::~Tank_Boss();
//};
//
//
//
//
////Tank_Users
//class Tank_Users :public Tank                                                                                                    //定义己方坦克子类
//{
//public:
//	Tank_Users(Map &map,int id, int blood = 100, int armour = 0, int speed = 1, Color color = white, int direction = 0);
//	~Tank_Users();
//	int getID();
//private:
//	int identification;
//};


#endif // !_TANK_H