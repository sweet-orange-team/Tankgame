#pragma once
#ifndef _TANK_H
#define _TANK_H

#include<iostream>
using namespace std;
#include"Console.h"
#include"Map.h"
enum Color {					//ö����ɫ����
	yellow, gray, white, pink, red
};
class Tank						//̹�˻���
{
public:
	Tank(Color color, int direction , int blood , int speed , int armour );
    Tank();
	~Tank();
	//void show(Console console, int direction=0, int x=40, int y=50);			//�ڵ�ͼ�����̹��||���У�����̨���ܲ������
	void append(Map &Map, int x = 40, int y = 50);
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
	Color color;
	int direction;
	int blood;
	int speed;
	int armour;
};

#endif // !_TANK_H

class Tank_Users :public Tank {             //����̹������
public:
    Tank_Users(Color color, int direction , int blood , int speed , int armour , int id );
    ~Tank_Users();
    int getID();
private:
    int identification;
};

class Tank_Enemies :public Tank {             //�з�̹������
public:
    Tank_Enemies(Color color , int direction , int blood , int speed, int armour , int id );
    ~Tank_Enemies();
    int getID();
private:
    int identification;
};

class Tank_Ordinary :public Tank_Enemies {             //��ͨ�з�̹������
public:
    Tank_Ordinary( int direction , int blood , int speed , int armour , int id );
    ~Tank_Ordinary();
};

class Tank_Boss :public Tank_Enemies {             //BOSS�з�̹������
public:
    Tank_Boss::Tank_Boss(int direction , int blood , int speed , int armour , int id );
    Tank_Boss::~Tank_Boss();
};
