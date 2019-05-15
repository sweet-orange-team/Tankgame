#include<iostream>
#include"Console.h"
#include"Map.h"
#include"Prop.h"
#include"Tank.h"
using namespace std;

Prop::Prop(int x, int y, int isSee)
{
    this->x = x;
    this->y = y;
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
    Map::map[this->x][this->y][0] = 3;                        //??????????????????
}


void BulletProp::isGet(Tank&Tank)                              //增加子弹伤害
{
    int a;
    for (int i = -1; i < 2; i++) 
    {
        for (int j = -2; j < 4; j++)
        {
            if (this->x == Tank.getX() + i|| this->x+1 == Tank.getX() + i && this->y == Tank.getY() + j)a = 1;
            else a = 0;
        }
    }
    while (a)
    {

    }

}


void InvincibleProp::isGet(Tank&Tank)                           //子弹0伤害，触之即死
{
    int a;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -2; j < 4; j++)
        {
            if (this->x == Tank.getX() + i || this->x + 1 == Tank.getX() + i && this->y == Tank.getY() + j)a = 1;
            else a = 0;
        }
    }
    while (a)
    {

    }

}










                //y-2  y   y+3
   //x-1		//     ■
   //x+0 		//■   ■   ■
   //x+1        //■        ■