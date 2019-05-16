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

class Tank                                      //̹�˻���
{
public:
    Tank(int x , int y , Color color , int direction );
    ~Tank();
    virtual void append();						//��ӽ���ͼ
    virtual void show();
    virtual void clear();
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

class TankUser:public Tank					 //̹���û���
{
public:
	TankUser(int x=20,int y=50,Color color = yellow, int direction = 0);
	~TankUser();
	static int blood;
	static int score;
    static int attack;
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
    Bullet *bullet[100];
	int bulletNum=0;
};

class TankEnemy:public Tank
{
public:
    static int selfboom;
	TankEnemy(int x = 4, int y = 50, Color color = pink, int direction = 1,int score=5, int blood=3);
	~TankEnemy();
	void move();
	void append();
    void isShot(TankUser&Tank);
	int isAlive();
private:
	int Alive = 1;
	int score;
    int blood;
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