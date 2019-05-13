#pragma once
#ifndef _BULLET_H
#define _BULLET_H

#include<iostream>
#include"Map.h"
using namespace std;

class Bullet                                                     //�ӵ�����
{
public:
    Bullet(Map &map, int x,int y,int direction,int isSee=1);
    ~Bullet();
	virtual void show();
	virtual void clear();
    virtual void append();                              //�����ͼ
    virtual void move(int step=1);								//�ӵ��ƶ�
	char *body = u8"��";
	virtual char* getBody();
	int isSee;
protected:
    int direction;
    int x, y;
	Map mainMap;
};

#endif !_BULLET_H

