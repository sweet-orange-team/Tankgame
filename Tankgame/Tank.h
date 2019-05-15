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
	Tank(int x=20,int y=50,Color color = yellow, int direction = 0);
	~Tank();
	void append();						//��ӽ���ͼ
	void move(int direction);           //�ƶ�̹��
	void show();
	void clear();
	void shoot();
	void bulletMove();
	int getDir();								 //���ط���
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
	Bullet *bullet1;
	Bullet *bullet2;
	Bullet *bullet3;
	Bullet *bullet4;
	Bullet *bullet5;
	int bulletNum=0;
};

class TankEnemy:public Tank
{
public:
	TankEnemy(int x = 4, int y = 50, Color color = pink, int direction = 1);
	~TankEnemy();
	void move();
	int isAlive();
private:
	int Alive = 1;
};



class Tank_Enemies                                                                                                   //�з�̹����
{
public:
	Tank_Enemies();
	~Tank_Enemies();
	void allEnemyMove();
	void del();
	void add();
private:
	Map mainMap;
	TankEnemy* enemy1;
	TankEnemy* enemy2;
	TankEnemy* enemy3;
	TankEnemy* enemy4;
	TankEnemy* enemy5;
	int enemyNum = 0;
};
//
//
//
//class Tank_Ordinary :public Tank_Enemies                                                                                          //��ͨ�з�̹������
//{
//public:
//	Tank_Ordinary(Map &map, int id, int blood = 100, int armour = 0, int speed = 1, Color color = white, int direction = 0);
//	~Tank_Ordinary();
//};
//
//
//
//class Tank_Boss :public Tank_Enemies                                                                                              //BOSS�з�̹������
//{
//public:
//	Tank_Boss::Tank_Boss(Map &map, int id, int blood = 100, int armour = 0, int speed = 1, Color color = white, int direction = 0);
//	Tank_Boss::~Tank_Boss();
//};
//
//
//
//
////Tank_Users
//class Tank_Users :public Tank                                                                                                    //���强��̹������
//{
//public:
//	Tank_Users(Map &map,int id, int blood = 100, int armour = 0, int speed = 1, Color color = white, int direction = 0);
//	~Tank_Users();
//	int getID();
//private:
//	int identification;
//};


#endif // !_TANK_H