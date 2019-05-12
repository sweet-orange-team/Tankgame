#pragma once
#ifndef _BULLET_H
#define _BULLET_H

#include<iostream>
using namespace std;
#include"Console.h"
#include"Map.h"

class Bullet                                                     //�ӵ�����
{
public:
    Bullet(int harm, int speed, Color col, Tank&tank);
    ~Bullet();
    virtual void append(Map &Map);                              //����Ļ����ʾ�ӵ�
    virtual void move(Map& Map, Tank&Tank);						//�ӵ��ƶ�
protected:
    Color color;
    int direction;
    int speed;
    int harm;
    int x, y;
};

#endif !_BULLET_H

