#include"Tank.h"
#include"Console.h"
#include"Bullet.h"
#include"Map.h"
using namespace std;

Bullet::Bullet(int x, int y, int dir, int isSee)                            //初始化子弹属性
{
	this->x = x;
	this->y = y;
	this->direction = dir;
	this->isSee = isSee;
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
void Bullet::append()                                                        //在地图上更新子弹
{
	Map::map[this->x][this->y][0] = 3;
}

void Bullet::move(int step)                         //子弹移动
{
	this->clear();
	switch (direction)
	{
	case 0:
		if (this->x >= step * 2) {
			Map::map[this->x][this->y][0] = 0;
			//todo 子弹击中坦克有时候不消失
			if (Map::map[x - 1][y][0] == 4 || Map::map[x - 1][y + 1][0] == 4) {	//判断前面有没有敌方坦克
				this->x -= step;
				append();
				clear();
				this->x = 0;
				this->y = 90;
				append();
				clear();
			}
			else
			{
				this->x -= step;
				append();
				show();
			}
			break;
		}
		else
		{
			Map::map[this->x][this->y][0] = 0;
			this->x = 0;
			this->y = 90;
			append();
			clear();
		}
	default:
		break;
	}
}

char * Bullet::getBody()
{
	return Console::U2G(this->body);
}


