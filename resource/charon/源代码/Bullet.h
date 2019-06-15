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
	virtual void show();				//�ڿ���̨����ӵ�
	virtual void clear();				//�ڿ���̨����ӵ�
    virtual void append();              //�����ͼ
    virtual void move(int step=1);		//�ӵ��ƶ�
	char *body = u8"��";
	virtual char* getBody();
	void setBody(char *body);
	int getX();					//�õ��ӵ�X����
	int getY();					//�õ��ӵ�Y����
	int isSee;					//�ӵ��Ƿ�ɼ��ı�ʾ
protected:
    int direction;
    int x, y;
	int attack;
	int number;
};


#endif !_BULLET_H

