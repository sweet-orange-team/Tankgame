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
    Bullet(Map &map, int x,int y,int direction,int isSee=1);
    ~Bullet();
	virtual void show();
	virtual void clear();
    virtual void append();                              //加入地图
    virtual void move(int step=1);								//子弹移动
	char *body = u8"◆";
	virtual char* getBody();
	int isSee;
protected:
    int direction;
    int x, y;
	Map mainMap;
};

#endif !_BULLET_H

