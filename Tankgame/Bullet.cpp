#include"Tank.h"
#include"Console.h"
#include"Bullet.h"
#include"Map.h"
using namespace std;

Bullet::Bullet(int x, int y, int dir, int isSee,char* body,int attack,int number)                            //初始化子弹属性
{
	this->x = x;
	this->y = y;
	this->direction = dir;
	this->isSee = isSee;
	this->body = body;
	this->attack = attack;
	this->number = number;
}
Bullet::~Bullet() { }

void Bullet::show() {
	if (isSee) {
		Console::setCursorPosition(x, y);
		cout << this->getBody();
	}
}
void Bullet::clear() {
	Console::setCursorPosition(x, y);
	cout << "  ";
}
void Bullet::append()								//在地图上更新子弹
{
	Map::map[this->x][this->y][0] = number;
	Map::map[x][y+1][0] = number;
}

void Bullet::move(int step)                         //子弹移动
{
	this->clear();
	switch (direction)
	{
	case 0:
		if (this->x >=2&&(this->x!=0&&this->y!=90)) {
			this->x -= step;				//提前预定下一个抵达点，子弹坐标增加
			if (Map::map[x][y][0]!=0 && Map::map[x][y][0] != 6)
			{
				append();
				this->x = 1; this->y = 90;
			}
			else show();
		}
		else
		{
			this->x = 0;
			this->y = 90;
			clear();
		}
		break;
	case 1:
		
		if (this->x <= 27 && (this->x != 0 && this->y != 90)) {
			this->x += step;						//提前预定下一个抵达点，子弹坐标增加
			if (Map::map[x][y][0] != 0 && Map::map[x][y][0] != 6)
			{
				append();
				this->x = 0; this->y = 90;
			}
			else show();
		}
		else
		{
			this->x = 0;
			this->y = 90;
			clear();
		}

		break;
	case 2:
		if (this->y >= 4  && (this->x != 0 && this->y != 90)) {
			this->y -= step * 2;
			if (Map::map[x][y][0] != 0&&Map::map[x][y][0] != 6)
			{
				append();
				this->x = 1; this->y = 90;
			}
			else show();
		}
		else
		{
			this->x = 0;
			this->y = 90;
			clear();
		}
		break;
	case 3:
		if (this->y <= 74&& (this->x != 0 && this->y != 90)) {
			this->y += step * 2;	
			if (Map::map[x][y][0] != 0&& Map::map[x][y][0]!=6)
			{
				append();
				this->x = 0; this->y = 90;
			}
			else show();
		}
		else
		{
			this->x = 0;
			this->y = 90;
			clear();
		}
		break;
	default:
		break;
	}
}

char * Bullet::getBody()
{
	return Console::U2G(this->body);
}

void Bullet::setBody(char* body)
{
	this->body = body;
}

int Bullet::getX()
{
	return this->x;
}

int Bullet::getY()
{
	return this->y;
}
