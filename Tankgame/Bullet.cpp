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

void Bullet::move(int step)                         //�ӵ��ƶ�
{
	this->clear();
	switch (direction)
	{
	case 0:
		Map::map[this->x][this->y][0] = 0;
		if (this->x >= step * 2&&(this->x!=1&&this->y!=90)) {
			//todo �ӵ�����̹����ʱ����ʧ
			this->x -= step;
			append();
			clear();
			if (Map::map[x - 1][y][0] == 4 || Map::map[x - 1][y + 1][0] == 4) {	//�ж�ǰ����û�ез�̹��
				this->x = 1;
				this->y = 90;
			}
			else show();
			break;
		}
		else
		{
			this->x = 1;
			this->y = 90;
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


