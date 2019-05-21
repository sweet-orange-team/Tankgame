#include<iostream>
#include"Console.h"
#include"Map.h"
#include"Prop.h"
#include"Tank.h"
#include"windows.h"
#include"Control.h"
using namespace std;

//Prop class 
Prop::Prop(int x, int y, char*body)
{
	this->x = x;
	this->y = y;
	this->body = body;
}

Prop::~Prop() { }

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
char* BulletProp::body = u8"◆";
int BulletProp::attack = 1;
BulletProp::BulletProp(int x, int y, char*body) :Prop(x, y, body) { }

BulletProp::~BulletProp() { }

void BulletProp::isGet()                      //道具效果
{
    this->clearProp();
	BulletProp::body = u8"▲";
	BulletProp::attack = 2;
}

void BulletProp::Recover()                    //复原
{
	BulletProp::body = u8"◆";
	BulletProp::attack = 1;
}

void BulletProp::showProp()
{
    Console::setCursorPosition(x, y);
    cout << u8"▲";
}

//InvincibleProp class
int InvincibleProp::selfboom = 1;

InvincibleProp::InvincibleProp(int x, int y, char*body) :Prop(x, y, body) { }

InvincibleProp::~InvincibleProp() { }

void InvincibleProp::isGet()          //触之即死
{
	this->clearProp();
    InvincibleProp::selfboom = 0;
}

void InvincibleProp::Recover()
{
    InvincibleProp::selfboom = 1;
}

//BloodProp class
BloodProp::BloodProp(int x, int y, char*body):Prop(x, y, body) { }

BloodProp::~BloodProp(){ }

void BloodProp::isGet()
{
    TankUser::blood++;
    this->clearProp();
}

void BloodProp::Recover(){ }

//prop class 
int props::count = 0;
int props::num = 0;
props::props() { }

props::~props() { }

void props::initProp()
{
    props::num = (Console::Random(0,10)%3)+1;
	switch (props::num)
	{
	case 1:
	{
		prop1 = new BulletProp(Console::Random(4, 26), Console::Random(4, 73));
		prop1->showProp();
		prop1->append();
		break;
	}
	case 2:
	{
		prop2 = new InvincibleProp(Console::Random(4, 26), Console::Random(4, 73));
		prop2->showProp();
		prop2->append();
		break;
	}
    case 3:
    {
        prop3 = new BloodProp(Console::Random(4, 26), Console::Random(4, 73));
        prop3->showProp();
        prop3->append();
        break;
    }
	default:
		break;
	}
}

void props::UseProp(TankUser&Tank)
{
    int isget = 0;
    if (props::count % 125 == 0) {
        initProp();
        props::count = 0;
    }

    switch (props::num)
    {
    case 1:
        if (prop1->IsGet(Tank))
        {
            isget = 1;
            prop1->isGet();
            break;
        }
    case 2:
        if (prop2->IsGet(Tank))
        {
            isget = 1;
            prop2->isGet();
            break;
        }
    case 3:
        if (prop3->IsGet(Tank))
        {
            isget = 1;
            prop3->isGet();
            break;
        }
    default:
        break;
    }
    if (isget) {
        if (props::count == 63)
        {
            switch (props::num)
            {
            case 1:
            {
                prop1->Recover();
                delete prop1;
                break;
            }
            case 2:
            {
                prop2->Recover();
                delete prop2;
                break;
            }
            case 3:
            {
                delete prop3;
                break;
            }
            default:
                break;
            }
            props::count = 0;
        }
    }
    else if (props::count == 124)
    {
        switch (props::num)
        {
        case 1:
        {
            prop1->clearProp();
            delete prop1;
            break;
        }
        case 2:
        {
            prop2->clearProp();
            delete prop2;
            break;
        }
        case 3:
        {
            prop3->clearProp();
            delete prop3;
            break;
        }
        default:
            break;
        }
    }
    props::count++;
}







//y-2  y   y+3
//x-1		//     ■
//x+0 		//■   ■   ■
//x+1       //■        ■