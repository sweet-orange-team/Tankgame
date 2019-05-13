#include"Tank.h"
#include"Console.h"
#include"Bullet.h"
using namespace std;

Bullet::Bullet(Map &map,int x,int y,int dir,int isSee)                            //��ʼ���ӵ�����
{
	this->x = x;
	this->y = y;
	this->direction = dir;
	this->mainMap = map;
	this->isSee = isSee;
}
Bullet::~Bullet() { }

void Bullet::show() {
	Console::setCursorPosition(x, y);
	cout << this->getBody();
}
void Bullet::clear() {
	Console::setCursorPosition(x, y);
	cout << "  ";
}
void Bullet:: append()                                                         //����Ļ����ʾ�ӵ�
{
	mainMap.map[this->x][this->y][0] = 3;
}

void Bullet::move(int step)                                                  //�ӵ��ƶ�
{
	this->clear();
	switch (direction)
	{
	case 0:
		mainMap.map[this->x][this->y][0] = 0;
		this->x-=step;
		mainMap.map[this->x][this->y][0] = 3;
		break;
	case 1:
		mainMap.map[this->x][this->y][0] = 0;
		this->x+=step;
		mainMap.map[this->x ][this->y][0] = 3;
		break;
	case 2:
		mainMap.map[this->x][this->y][0] = 0;
		this->y-=step;
		mainMap.map[this->x][this->y][0] = 3;
		break;
	case 3:
		mainMap.map[this->x][this->y][0] = 0;
		this->y += step;
		mainMap.map[this->x][this->y][0] = 3;
		break;
	default:
		break;
	}
	this->show();
}

char * Bullet::getBody()
{
	return Console::U2G(this->body);
}


