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


//̹�˻���
class Tank   
{
public:
    Tank(int x , int y , Color color , int direction );
    ~Tank();
    void append();						//��ӽ���ͼ
    void show();
    void clear();
    int getX();
    int getY();
protected:
    const char body[4][3][6] = {
        // ��
        {
            { 0, 0, 1, 1, 0, 0 },			//��ͼ�����ʱ��һ����ռ������λ�ã�����ռ��λ�����������������ó��������
            { 1, 1, 1, 1, 1, 1, },			//  ��
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
    int x, y;                                //x,yȡ�Ź����е�
    int direction;
    char* n = u8"��";

};


//̹���û���
class TankUser:public Tank					 
{
public:
	TankUser(int x=27,int y=40,Color color = yellow, int direction = 0);
	~TankUser();
	static int blood;
	static int score;
	void move(int direction);                //�ƶ�̹��
	void shoot();
	void bulletMove();
	int isAlive();
	int getDir();							 //���ط���
    Bullet** getBullet();
protected:
	Color color;
	int speed;
	int armour;
    Bullet *bullet[30];
	int bulletNum;
};


//�з�̹����
class TankEnemy:public Tank
{
public:
    static int selfboom;
	TankEnemy(int x = 4, int y = 50, Color color = green, int direction = 1,int score=5000, int blood=1);
	~TankEnemy();
	void move();
	void append();
    void isShoot();
	int isAlive();
private:
	int Alive = 1;
	int score;
    int blood;
	double speed = 0.3;
	double newX;
};


//�з�̹��Ⱥ
class TankEnemies                                                                                                   //�з�̹����
{
public:
	TankEnemies();
	~TankEnemies();
	void allEnemyMove();
public:
	TankEnemy* enemies[3];
	int enemyNum = 3;
};


#endif // !_TANK_H