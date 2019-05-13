#include"Tank.h"
#include"Console.h"
#include"ctime"
#include"Bullet.h"
using namespace std;


//基类

Tank::Tank(Map &map, int x, int y, int blood, int armour, int speed, Color color, int direction)                                //构造函数，初始化坦克默认参数
{
	this->mainMap = map;
	this->color = color;
	this->direction = direction;
	this->blood = blood;
	this->speed = speed;
	this->armour = armour;
	this->x = x;
	this->y = y;
}


Tank::~Tank()
{
}

int Tank::getDir()                              //返回坦克方向
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



void Tank::append()                                                 //在地图上输出坦克 
{
	for (int i = -1; i <= 1; i++) {
		for (int j = -2; j <= 3; j++) {
			mainMap.map[x + i][y + j][0] = 2;
			mainMap.map[x + i][y + j][1] = color;
		}
	}
}


void Tank::move(int d)                                                                              //移动坦克
{
	Console::setColor(yellow);
	this->direction = d;
	switch (d) {
	case 0: {
		if (this->x >= 3) {
			this->clear();
			this->x -= 1;
			Console::setCursorPosition(this->x - 1, this->y - 2);
			cout << "  " << Console::U2G(n) << "  ";
			Console::setCursorPosition(this->x + 0, this->y - 2);
			cout << Console::U2G(n) << Console::U2G(n) << Console::U2G(n);
			Console::setCursorPosition(this->x + 1, this->y - 2);
			cout << Console::U2G(n) << "  " << Console::U2G(n);
		}
		break;
	}
	case 1: {
		if (this->x <= 26) {
			this->clear();
			this->x += 1;
			Console::setCursorPosition(this->x - 1, this->y - 2);
			cout << Console::U2G(n) << "  " << Console::U2G(n);
			Console::setCursorPosition(this->x + 0, this->y - 2);
			cout << Console::U2G(n) << Console::U2G(n) << Console::U2G(n);
			Console::setCursorPosition(this->x + 1, this->y - 2);
			cout << "  " << Console::U2G(n) << "  ";
		}
		break;
	}
	case 2: {
		if (this->y >= 6) {
			this->clear();
			this->y -= 2;
			Console::setCursorPosition(this->x - 1, this->y - 2);
			cout << "  " << Console::U2G(n) << Console::U2G(n);
			Console::setCursorPosition(this->x + 0, this->y - 2);
			cout << Console::U2G(n) << Console::U2G(n) << "  ";
			Console::setCursorPosition(this->x + 1, this->y - 2);
			cout << "  " << Console::U2G(n) << Console::U2G(n);
		}
		break;
	}
	case 3: {
		if (this->y <= 73) {
			this->clear();
			this->y += 2;
			Console::setCursorPosition(this->x - 1, this->y - 2);
			cout << Console::U2G(n) << Console::U2G(n) << "  ";
			Console::setCursorPosition(this->x + 0, this->y - 2);
			cout << "  " << Console::U2G(n) << Console::U2G(n);
			Console::setCursorPosition(this->x + 1, this->y - 2);
			cout << Console::U2G(n) << Console::U2G(n) << "  ";
		}
		break;
	}
	}
	append();
	bulletMove();
	Console::setColor(black);
}

void Tank::clear() {
	for (int i = -1; i <= 1; i++) {
		Console::setCursorPosition(this->x + i, this->y - 2);
		cout << "      ";
	}
	for (int i = -1; i <= 1; i++) {
		for (int j = -2; j <= 3; j++) {
			mainMap.map[x + i][y + j][0] = 0;
			mainMap.map[x + i][y + j][1] = color;
		}
	}
}


void Tank::shoot() {

	switch (direction)
	{
	case 0:
	{
		
		
		break; 
	}
	default:
		break;
	}
}

void Tank::bulletMove()
{
	
}


