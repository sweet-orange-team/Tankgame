#pragma once
#ifndef _TANK_H
#define _TANK_H

#include<iostream>
#include"Map.h"
#include"Bullet.h"
using namespace std;

enum Color {					//枚举颜色变量
	yellow = 6, gray = 7, white = 15, pink = 12, red = 4, black = 15, green = 2,blue = 1
};


//坦克基类
class Tank   
{
public:
    Tank(int x , int y , Color color , int direction );
    ~Tank();
    void append();		//添加进地图
    void show();		//在控制台输出坦克		
    void clear();		//在控制台清除坦克
	virtual void shoot() = 0;			//控制坦克射击
	virtual void bulletMove() = 0;		//控制坦克发射的子弹移动
	virtual int isAlive() = 0;			//判断坦克是否存活
    int getX();			//获得坦克的X坐标
    int getY();			//获得坦克的Y坐标
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
	Bullet *bullet[30];					//坦克的30发子弹
	int bulletNum;						//判断打到第几发
    int x, y;                           //x,y取九宫格中点
    int direction;
    char* n = u8"■";

};


//坦克用户类
class TankUser:public Tank			//继承坦克基类
{
public:
	TankUser(int x=27,int y=40,Color color = yellow, int direction = 0);
	~TankUser();
	static int blood;				//坦克的血量
	static int score;				//用户的分数
	void move(int direction);		  
	void shoot();
	void bulletMove();
	int isAlive();
	int getDir();					//得到坦克的朝向
protected:
	Color color;
	int speed;
};


//敌方坦克类
class TankEnemy:public Tank
{
public:
    static int selfboom;		//敌方坦克与我方坦克相撞产生的自爆上海
	static int shootspeed;		//控制坦克的射击速度
	TankEnemy(int x = 4, int y = 50, Color color = green, int direction = 1,int score=5000, int blood=1);
	~TankEnemy();
	void move();
	void shoot();
	void bulletMove();
	void append(int num=4);
    void isShot();				//判断是否有子弹击中自身
	int isAlive();
private:
	int Alive = 1;				//存活标志
	int score;
    int blood;
	double speed = 0.3;			//坦克的移动速度
	double newDistance=0;		//坦克是否前进一格
	int shouldShoot = 0;		//因为敌方坦克是在每个循环都移动一次，所以添加一个计数器降低射击频率
};


//敌方坦克群
class TankEnemies                                                                                                   //敌方坦克类
{
public:
	TankEnemies();
	~TankEnemies();
	void allEnemyMove();		//控制每个坦克自动行走
public:
	TankEnemy* enemies[3];		//每次只出现三个坦克
	int enemyNum = 3;
};


#endif // !_TANK_H