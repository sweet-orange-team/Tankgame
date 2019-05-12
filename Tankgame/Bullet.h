#pragma once
#ifndef _BULLET_H
#define _BULLET_H

#include<iostream>
using namespace std;
#include"Console.h"
#include"Map.h"

class Bullet                                                     //子弹基类
{
public:
    Bullet(int x,int y);
    ~Bullet();
    virtual void append(Map &Map);                              //在屏幕上显示子弹
    virtual void move();						//子弹移动
	char *body = u8"◆";
	virtual char* body();
protected:
    Color color;
    int direction;
    int x, y;
	
};

#endif !_BULLET_H

