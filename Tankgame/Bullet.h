#pragma once
#ifndef _BULLET_H
#define _BULLET_H

#include<iostream>
#include"Map.h"
using namespace std;

class Bullet                                            //�ӵ�����
{
public:
    Bullet(int x,int y,int direction,int isSee=1,char* body= u8"��",int attack=1,int number=3);
    ~Bullet();
	virtual void show();
	virtual void clear();
    virtual void append();                              //�����ͼ
    virtual void move(int step=1);						//�ӵ��ƶ�
	char *body = u8"��";
	virtual char* getBody();
	void setBody(char *body);
	int getX();
	int getY();
	int isSee;
protected:
    int direction;
    int x, y;
	int attack;
	int number;
};


#endif !_BULLET_H

