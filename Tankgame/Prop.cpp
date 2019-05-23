#include<iostream>
#include"Console.h"
#include"Map.h"
#include"Prop.h"
#include"Tank.h"
#include"windows.h"
#include"Control.h"
#include<conio.h>
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
    int a = 0,i,j;
    while (!a) {
        for (i = Tank.getX() - 2, j = Tank.getY() - 2; j < Tank.getY() + 4; j++)
        {
            if (Map::map[i][j][0] == 5 && Tank.getDir() == 0) a = 1;
        }
        for ( i = Tank.getX() + 2,  j = Tank.getY() - 2; j < Tank.getY() + 4; j++)
        {
            if (Map::map[i][j][0] == 5 && Tank.getDir() == 1) a = 1;
        }
        for ( i = Tank.getX() - 1,  j = Tank.getY() - 3; i <= Tank.getX() + 1; i++)
        {
            if (Map::map[i][j][0] == 5 && Tank.getDir() == 2) a = 1;
        }
        for ( i = Tank.getX() - 1,  j = Tank.getY() + 4; i <= Tank.getX() + 1; i++)
        {
            if (Map::map[i][j][0] == 5 && Tank.getDir() == 3) a = 1;
        }
        break;
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
    char*n= u8"▲";
    Console::setCursorPosition(x, y);
    cout << Console::U2G(n);
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
int props::isget = 0;
int props::judge = 0;
int props::timercount = 0;
void props::timer()                         //计时器
{
    Console::setCursorPosition(2, 85);
    Console::setColor(11);
    switch (timercount)
    {
    case 0:cout << "10"; break;
    case 25:cout << " 9"; break;
    case 50:cout << " 8"; break;
    case 75:cout << " 7"; break;
    case 100:cout << " 6"; break;
    case 125:cout << " 5"; break;
    case 150:cout << " 4"; break;
    case 175:cout << " 3"; break;
    case 200:cout << " 2"; break;
    case 225:cout << " 1"; break;
    default:break;
    }
    Console::setColor(white);
}
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

    if (props::count == 0) {
        initProp();
        isget=0;
        judge = 1;
    }

    switch (props::num)
    {
    case 1:
        if (prop1->IsGet(Tank))
        {
            timercount = count;
            isget = 1;
            prop1->isGet();
            break;
        }
    case 2:
        if (prop2->IsGet(Tank))
        {
            timercount = count;
            isget = 1;
            prop2->isGet();
            break;
        }
    case 3:
        if (prop3->IsGet(Tank))
        {
            timercount = 250;
            isget = 1;
            prop3->isGet();
            break;
        }
    default:
        break;
    }
    if (isget) {
        timer();
        if (props::count == 250)
        {
                Console::setCursorPosition(2, 85);
                Console::setColor(white);
                cout << "  "; 
            switch (props::num)
            {
            case 1:
            {
                prop1->Recover();
                isget = 0;
                delete prop1;
                break;
            }
            case 2:
            {
                prop2->Recover();
                isget = 0;
                delete prop2;
                break;
            }
            case 3:
            {
                isget = 0;
                delete prop3;
                break;
            }
            default:
                break;
            }
            props::count = 2;
            judge = 0;
        }
    }
    else if (props::count == 252&&judge)
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
            props::count = -1;
        }
    if (judge == 0 && count == 250)count = -1;
    props::count++;
    props::timercount++;
}







//y-2  y   y+3
//x-1		//     ■
//x+0 		//■   ■   ■
//x+1       //■        ■