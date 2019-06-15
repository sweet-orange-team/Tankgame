#pragma once
#ifndef _BULLET_H
#define _BULLET_H

#include<iostream>
#include"Map.h"
using namespace std;

class Bullet                                            //子弹基类
{
public:
    Bullet(int x,int y,int direction,int isSee=1,char* body= u8"◆",int attack=1,int number=3);
    ~Bullet();
	virtual void show();				//在控制台输出子弹
	virtual void clear();				//在控制台清除子弹
    virtual void append();              //加入地图
    virtual void move(int step=1);		//子弹移动
	char *body = u8"◆";
	virtual char* getBody();
	void setBody(char *body);
	int getX();					//得到子弹X坐标
	int getY();					//得到子弹Y坐标
	int isSee;					//子弹是否可见的标示
protected:
    int direction;
    int x, y;
	int attack;
	int number;
};


#endif !_BULLET_H

