#include<iostream>
#include"Console.h"
#include"Map.h"
#include"Prop.h"
#include"Tank.h"
#include"windows.h"
using namespace std;

//Prop class 
Prop::Prop(int x, int y, char*body, int isSee)
{
    this->x = x;
    this->y = y;
    this->body = body;
    this->isSee = isSee;
}

Prop::~Prop(){ }

char* Prop::getBody()
{
    return Console::U2G(this->body);
}

void Prop::showProp()                                        //想要每20s刷一个道具
{
    if (isSee) {
        Console::setCursorPosition(x, y);
		cout << this->getBody();
    }
}

void Prop::clearProp()                                        //20s后消失
{
    Console::setCursorPosition(x, y);
    cout << "  ";
}

void Prop::append()
{
    Map::map[this->x][this->y][0] = 5;                        
}


BulletProp::BulletProp(int x, int y, char*body, int isSee) :Prop(x, y, body, isSee){ }

BulletProp::~BulletProp(){ }

void BulletProp::isGet(TankUser&Tank)                          //增加子弹伤害
{
    int a;
    for (int i = -1; i < 2; i++) 
    {
        for (int j = -2; j < 4; j++)
        {
            if (Map::map[i][j][0] == 5) a = 1;
            else a = 0;
        }
    }
    while (a)                                                     //子弹伤害1->3,持续时间10s
    {
        this->clearProp();
        Tank.attack = 3;
        Sleep(10000);
        Tank.attack = 1;
    }

}

InvincibleProp::InvincibleProp(int x, int y, char*body, int isSee) :Prop(x, y, body, isSee) { }

InvincibleProp::~InvincibleProp() { }

void InvincibleProp::isGet(TankUser&Tank,TankEnemy&tank)          //触之即死
{ 
    int a;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -2; j < 4; j++)
        {
            if (Map::map[i][j][0] == 5) a = 1;
            else a = 0;
           // if (this->x == Tank.getX() + i || this->x + 1 == Tank.getX() + i && this->y == Tank.getY() + j)a = 1;
           //else a = 0;
        }
    }
    while (a)                                                     //敌人自爆伤害减为0，持续时间10s
    {
        this->clearProp();
        tank.selfboom = 0;
        Sleep(10000);
        tank.selfboom = 1;
    }

}

//prop class 
int prop::propNum = 0;
prop::prop(){ }

prop::~prop(){ }

void prop::add(int x,int y)
{
    switch (propNum % 2)
    {
        case 0:
        {
            *prop1 = BulletProp(x, y, u8"▲",1);
            Sleep(20000);
            prop1->clearProp();
            break;;
        }
        case 1:
        {
            *prop2 = InvincibleProp(x, y, u8"★", 1);
            Sleep(20000);
            prop2->clearProp();
            break;
        }
        default:
            break;
    }
    propNum++;
}

void prop::del(){ }







                //y-2  y   y+3
   //x-1		//     ■
   //x+0 		//■   ■   ■
   //x+1        //■        ■