#include"Tank.h"
#include"Console.h"
#include"Bullet.h"
#include"Map.h"
using namespace std;

Bullet::Bullet(int x, int y, int dir, int isSee)                            //��ʼ���ӵ�����
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
void Bullet::append()                                                        //�ڵ�ͼ�ϸ����ӵ�
{
	Map::map[this->x][this->y][0] = 3;
}

void Bullet::move(int step)                                                  //�ӵ��ƶ�
{
	this->clear();
	switch (direction)
	{
	case 0:
		if (this->x >= step * 2) {
			Map::map[this->x][this->y][0] = 0;
			this->x -= step;
			append();
			this->show();
			break;
		}
		else
		{
			Map::map[this->x][this->y][0] = 0;
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


