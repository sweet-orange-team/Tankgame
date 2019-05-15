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

void Prop::showProp()
{
    if (isSee) {
        Console::setCursorPosition(x, y);
        cout << this->getBody();
    }
}

void Prop::clearProp()
{
    Console::setCursorPosition(x, y);
    cout << "  ";
}

void Prop::append()
{
    Map::map[this->x][this->y][0] = 3;                        //??????????????????
}

void Prop::isGet(Tank&Tank){ }

void BulletProp::isGet(Tank&Tank)
{

}