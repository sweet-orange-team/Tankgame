#pragma once
#ifndef _TANK_H
#define _TANK_H

#include<iostream>
#include"Map.h"
#include"Bullet.h"
using namespace std;

enum Color {					//ö����ɫ����
	yellow = 6, gray = 7, white = 15, pink = 12, red = 4, black = 15, green = 2
};

class Tank						//̹�˻���
{
public:
	Tank(Map &map,int x=20,int y=50,int blood = 100, int armour = 0, int speed = 1, Color color = white, int direction = 0);
	~Tank();
	virtual void append();						//��ӽ���ͼ
	virtual void move(int direction);           //�ƶ�̹��
	virtual void show();
	virtual void clear();
	virtual void shoot();
	void bulletMove();
	int getDir();           //���ط���
	int getX();
	int getY();
protected:
	const char body[4][3][6] = {
		// ��
		{
			{ 0, 0, 1, 1, 0, 0 },			//��ͼ�����ʱ��һ����ռ������λ�ã�����ռ��λ�����������������ó��������
			{ 1, 1, 1, 1, 1, 1,},			//  ��
			{ 1, 1, 0, 0, 1, 1 },			//������
		},									//��  ��
		// ��
		{
			{ 1, 1, 0, 0, 1, 1 },
			{ 1, 1, 1, 1, 1, 1 },
			{ 0, 0, 1, 1, 0, 0 },
		},
		// ��
		{
			{ 0, 0, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 1, 1 },
		},
		// ��
		{
			{ 1, 1, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 0, 0 },
		}
	};
protected:
	Color color;
	int direction;
	int blood;
	int speed;
	int armour;
	int x, y;                     //x,yȡ�Ź����е�
	char* n = u8"��";
	Map mainMap;
	Bullet *bullet1;
	Bullet *bullet2;
	Bullet *bullet3;
	Bullet *bullet4;
	Bullet *bullet5;
	int bulletNum=0;
};


//Tank_Enemies
class Tank_Enemies :public Tank                                                                                                   //�з�̹������
{
public:
	Tank_Enemies(Map &map, int id, int blood = 100, int armour = 0, int speed = 1, Color color = white, int direction = 0);
	~Tank_Enemies();
	int getID();
private:
	int identification;
};



class Tank_Ordinary :public Tank_Enemies                                                                                          //��ͨ�з�̹������
{
public:
	Tank_Ordinary(Map &map, int id, int blood = 100, int armour = 0, int speed = 1, Color color = white, int direction = 0);
	~Tank_Ordinary();
};



class Tank_Boss :public Tank_Enemies                                                                                              //BOSS�з�̹������
{
public:
	Tank_Boss::Tank_Boss(Map &map, int id, int blood = 100, int armour = 0, int speed = 1, Color color = white, int direction = 0);
	Tank_Boss::~Tank_Boss();
};




//Tank_Users
class Tank_Users :public Tank                                                                                                    //���强��̹������
{
public:
	Tank_Users(Map &map,int id, int blood = 100, int armour = 0, int speed = 1, Color color = white, int direction = 0);
	~Tank_Users();
	int getID();
private:
	int identification;
};


#endif // !_TANK_H