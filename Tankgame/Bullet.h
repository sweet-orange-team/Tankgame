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
    Bullet(int harm, int speed, Color col, Tank&tank);
    ~Bullet();
    virtual void append(Map &Map);                               //在屏幕上显示子弹
    virtual void move(Map& Map, Tank&Tank);                  //子弹移动
protected:
    const char body[3][6] =                                      
{
        { 0, 0, 0, 0, 0, 0 }, 
        { 0, 0, 1, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0 }
};
    Color color;
    int direction;
    int speed;
    int harm;
    int x, y;
};

#endif !_BULLET_H

