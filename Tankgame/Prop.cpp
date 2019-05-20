#include<iostream>
#include"Console.h"
#include"Map.h"
#include"Prop.h"
#include"Tank.h"
#include"windows.h"
using namespace std;

//Prop class 
Prop::Prop(int x, int y, char*body)
{
    this->x = x;
    this->y = y;
    this->body = body;
}

Prop::~Prop(){ }

int Prop::IsGet(TankUser&Tank)                        //判断是否被捡到
{
    int a = 0;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -2; j < 4; j++)
        {
            if (Map::map[Tank.getX() + i][Tank.getY() + j][0] == 5) a = 1;
        }
    }
    return a;
}

char* Prop::getBody()
{
    return Console::U2G(this->body);
}

void Prop::showProp()                                        
{
        Console::setCursorPosition(x, y);
		cout << this->getBody();
}

void Prop::clearProp()                                        
{
    Console::setCursorPosition(x, y);
    cout << "  ";
    Map::map[x][y][0] = 0;
}

void Prop::append()
{
    Map::map[this->x][this->y][0] = 5;                        
}

//BulletProp class
BulletProp::BulletProp(int x, int y, char*body) :Prop(x, y, body){ }

BulletProp::~BulletProp(){ }

void BulletProp::isGet(TankUser&Tank)                      //道具效果
{
        this->clearProp();
        Tank.attack = 3;                                   //增加子弹伤害
        for (int i = 0; i < 100; i++)
        {
            Tank.getBullet()[i]->body = u8"▲";            //改变子弹形状
        }      
    }

void BulletProp::Recover(TankUser&Tank)                    //复原
{
    for (int i = 0; i < 100; i++)
    {
        Tank.getBullet()[i]->body = u8"◆";
    }
    Tank.attack = 1;
}

//InvincibleProp class
InvincibleProp::InvincibleProp(int x, int y, char*body) :Prop(x, y, body) { }

InvincibleProp::~InvincibleProp() { }

void InvincibleProp::isGet(TankUser&Tank)          //触之即死
{ 
        this->clearProp();
        TankEnemy::selfboom = 0;
}

void InvincibleProp::Recover(TankUser&Tank)
{
    TankEnemy::selfboom = 1;
}

//prop class 
int props::propNum = 0;
props::props(){ }

props::~props(){ }

void props::initProp(TankUser&Tank)
{
        switch (propNum % 2)
        {
        case 0:
        {
            prop1 = new BulletProp(Console::Random(4, 26), Console::Random(4, 73));
            prop1->showProp();
            prop1->append();
            break;
        }
        case 1:
        {
            prop2 = new InvincibleProp(Console::Random(4, 26), Console::Random(4, 73));
            prop2->showProp();
            prop2->append();
            break;
        }
        default:
            break;
        }
        propNum++;
    }








                //y-2  y   y+3
   //x-1		//     ■
   //x+0 		//■   ■   ■
   //x+1        //■        ■