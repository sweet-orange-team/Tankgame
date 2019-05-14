#include"Tank.h"
#include"Console.h"
#include"ctime"
#include"Bullet.h"
#include"Map.h"
using namespace std;


//基类
int Tank::blood = 5;
int Tank::score = 0;
Tank::Tank(int x, int y,  Color color, int direction)                                //构造函数，初始化坦克默认参数
{
	this->color = color;
	this->direction = direction;
	this->blood = blood;
	this->speed = speed;
	this->armour = armour;
	this->x = x;
	this->y = y;
	append();
	bullet1=new Bullet(0,0,0);
	bullet2=new Bullet(0,0,0);
	bullet3=new Bullet(0,0,0);
	bullet4=new Bullet(0,0,0);
	bullet5=new Bullet(0,0,0);
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
			Map::map[x + i][y + j][0] = 2;
			Map::map[x + i][y + j][1] = color;
		}
	}
}


void Tank::move(int d)                                                                              //移动坦克
{
	Console::setColor(this->color);
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
	Console::setColor(black);
}

void Tank::clear() {
	for (int i = -1; i <= 1; i++) {
		Console::setCursorPosition(this->x + i, this->y - 2);
		cout << "      ";
	}
	for (int i = -1; i <= 1; i++) {
		for (int j = -2; j <= 3; j++) {
			Map::map[x + i][y + j][0] = 0;
		}
	}
}

void Tank::show() {
	Console::setColor(color);
	Console::setCursorPosition(this->x - 1, this->y - 2);
	cout << "  " << Console::U2G(n) << "  ";
	Console::setCursorPosition(this->x + 0, this->y - 2);
	cout << Console::U2G(n) << Console::U2G(n) << Console::U2G(n);
	Console::setCursorPosition(this->x + 1, this->y - 2);
	cout << Console::U2G(n) << "  " << Console::U2G(n);
	Console::setColor(white);
}

void Tank::shoot() {

	switch (direction)
	{
	case 0:
	{
		switch (bulletNum%5)
		{
		case 0: bullet1 =new  Bullet( this->x - 2, this->y, 0); (*bullet1).show(); break;
		case 1: bullet2 =new  Bullet( this->x - 2, this->y, 0); (*bullet2).show(); break;
		case 2: bullet3 =new  Bullet( this->x - 2, this->y, 0); (*bullet3).show(); break;
		case 3: bullet4 =new  Bullet( this->x - 2, this->y, 0); (*bullet4).show(); break;
		case 4: bullet5 =new  Bullet( this->x - 2, this->y, 0); (*bullet5).show(); break;
		default:
			break;
		}
		bulletNum++;
		break;
	}
	default:
		break;
	}
}

void Tank::bulletMove()
{
	(*bullet1).move();
	(*bullet2).move();
	(*bullet3).move();
	(*bullet4).move();
	(*bullet5).move();
}

int Tank::isAlive()
{
	if (Tank::blood == 0)return false;
	else return true;
}

TankEnemy::TankEnemy(int x , int y , Color color , int direction,int score ):Tank(x,y,color,direction)
{
	this->score = score;
	append();
}

TankEnemy::~TankEnemy()
{
}

void TankEnemy::move()
{
	if (this->isAlive()) {
		Console::setColor(this->color);
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
		else
		{
			Tank::blood--;
			clear();
			x = 2; y = 94;
			Alive = 0;
			show();
		}
		append();
		Console::setColor(black);
	}
	else
	{
		clear();
		x = 2; y = 94;
		show();
		append();
		Console::setColor(black);
	}
}

void TankEnemy::append()
{
	for (int i = -1; i <= 1; i++) {
		for (int j = -2; j <= 3; j++) {
			Map::map[x + i][y + j][0] = 4;
			Map::map[x + i][y + j][1] = color;
		}
	}
}

int TankEnemy::isAlive()
{
	for (int i = this->x - 1; i <= this->x + 2; i++) {
		for (int j = this->y - 2; j <= this->y + 3; j++) {
			if (Map::map[i][j][0] == 3) { 
				Alive = 0; Tank::score += this->score; break; 
			}
			if (Map::map[i][j][0] == 2) {
				Alive = 0; Tank::blood--; break;
			}
		}
	}
	return Alive;
}
