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


//坦克基类
class Tank   
{
public:
    Tank(int x , int y , Color color , int direction );
    ~Tank();
    void append();						//添加进地图
    void show();
    void clear();
    int getX();
    int getY();
protected:
    const char body[4][3][6] = {
        // 上
        {
            { 0, 0, 1, 1, 0, 0 },			//地图输出的时候一个■占了两个位置，被侵占的位置跳过输出，因此设置成这个样子
            { 1, 1, 1, 1, 1, 1, },			//  ■
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
    int x, y;                                //x,y取九宫格中点
    int direction;
    char* n = u8"■";

};


//坦克用户类
class TankUser:public Tank					 
{
public:
	TankUser(int x=27,int y=40,Color color = yellow, int direction = 0);
	~TankUser();
	static int blood;
	static int score;
	void move(int direction);                //移动坦克
	void shoot();
	void bulletMove();
	int isAlive();
	int getDir();							 //返回方向
    Bullet** getBullet();
protected:
	Color color;
	int speed;
	int armour;
    Bullet *bullet[30];
	int bulletNum;
};


//敌方坦克类
class TankEnemy:public Tank
{
public:
    static int selfboom;
	TankEnemy(int x = 4, int y = 50, Color color = green, int direction = 1,int score=5000, int blood=1);
	~TankEnemy();
	void move();
	void append();
    void isShoot();
	int isAlive();
private:
	int Alive = 1;
	int score;
    int blood;
	double speed = 0.3;
	double newX;
};


//敌方坦克群
class TankEnemies                                                                                                   //敌方坦克类
{
public:
	TankEnemies();
	~TankEnemies();
	void allEnemyMove();
public:
	TankEnemy* enemies[3];
	int enemyNum = 3;
};


#endif // !_TANK_H