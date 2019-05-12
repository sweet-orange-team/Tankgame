#include"Tank.h"
#include"Console.h"
#include"ctime"
using namespace std;


//基类

Tank::Tank(int blood , int armour, int speed , Color color , int direction )                                //构造函数，初始化坦克默认参数
{
	this->color = color;
	this->direction = direction;
	this->blood = blood;
	this->speed = speed;
	this->armour = armour;
    this->x = 40;
    this->y = 50;
    this->ifBullet = false;
}


Tank::~Tank()
{
}

 int Tank::getDir()                                                                                         //返回坦克方向
{
    return direction;
}

 int Tank::getX()
 {
     return this->x;
 }

 int Tank::getY()
 {
     return this->y;
 }

 bool Tank::getBullet()                                                                                     //判断是否发射子弹
 {
     return this->ifBullet;
 }
void Tank::append(Map& Map)                                                                                 //在地图上输出坦克 
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			Map.map[this->x + i][this->y + j][0] = this->body[this->direction][i][j];
			Map.map[this->x + i][this->y + j][1] = color;
		}
	}
}
void Tank::append(Map &Map, int a, int b)                                                                    //重载
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            Map.map[a + i][b + j][0] = this->body[this->direction][i][j];
            Map.map[a + i][b + j][1] = color;
        }
    }
}

void Tank::move(int d, Map& Map)                                                                              //移动坦克
{         
    this->direction = d;
    switch (d) {
    case 0: {
        x-=1;
        append(Map);
    }
    case 1: {
        x+=1;
        append(Map);
    }
    case 2: {
        y-=2;
        append(Map);
    }
    case 3: {
        y+=2;
        append(Map);
    }
    }
}


