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
	Tank(Color color = yellow, int direction = 0, int blood = 100, int speed = 1, int armour = 50);
	~Tank();
	//void show(Console console, int direction=0, int x=40, int y=50);			//�ڵ�ͼ�����̹��||���У�����̨���ܲ������
	void append(Map &Map, int x = 40, int y = 50);
protected:
	const char body[4][3][6] = {
		// UP
		{
			{ 0, 0, 1, 1, 0, 0 },
			{ 1, 1, 1, 1, 1, 1,},
			{ 1, 1, 0, 0, 1, 1 },
		},
		// DOWN
		{
			{ 1, 1, 0, 0, 1, 1 },
			{ 1, 1, 1, 1, 1, 1 },
			{ 0, 0, 1, 1, 0, 0 },
		},
		// LEFT
		{
			{ 0, 0, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 0, 0 },
			{ 0, 1, 1, 1, 1, 1 },
		},
		// RIGHT
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

