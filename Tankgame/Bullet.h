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
    Bullet(int x,int y);
    ~Bullet();
    virtual void append(Map &Map);                              //����Ļ����ʾ�ӵ�
    virtual void move();						//�ӵ��ƶ�
	char *body = u8"��";
	virtual char* body();
protected:
    Color color;
    int direction;
    int x, y;
	
};

#endif !_BULLET_H

