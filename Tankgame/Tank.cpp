#include"Tank.h"
#include"Console.h"
#include"ctime"
#include"Bullet.h"
#include"Map.h"
#include"Prop.h"
using namespace std;


//����
Tank::Tank(int x, int y, Color color, int direction)
{
	this->color = color;
	this->direction = direction;
	this->x = x;
	this->y = y;
}

Tank::~Tank() { }

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

void Tank::append()                                                 //�ڵ�ͼ�����̹�� 
{
	for (int i = -1; i <= 1; i++) {
		for (int j = -2; j <= 3; j++) {
			Map::map[x + i][y + j][0] = 2;
			Map::map[x + i][y + j][1] = color;
		}
	}
}

void Tank::clear() {
	for (int i = -1; i <= 1; i++) {
		Console::setCursorPosition(this->x + i, this->y - 2);
		cout << "      ";
	}
	for (int i = this->x - 1; i <= this->x + 1; i++) {
		for (int j = this->y - 2; j <= this->y + 3; j++) {
			Map::map[i][j][0] = 0;
		}
	}
}

int Tank::getX()
{
	return this->x;
}

int Tank::getY()
{
	return this->y;
}

//�û���
int TankUser::blood = 5;
int TankUser::score = 0;
TankUser::TankUser(int x, int y, Color color, int direction) :Tank(x, y, color, direction)          //���캯������ʼ��̹��Ĭ�ϲ���
{
	this->color = color;
	this->direction = direction;
	this->x = x;
	this->y = y;
	bulletNum = 0;
	append();
	for (int i = 0; i < 30; i++)
	{
		bullet[i] = new Bullet(0, 90, 0, 0, BulletProp::body, BulletProp::attack);
	}
}

TankUser::~TankUser()
{
}

int TankUser::getDir()                              //����̹�˷���
{
	return direction;
}

void TankUser::move(int d)                                                                              //�ƶ�̹��
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
			cout << "  " << Console::U2G(n) << "  ";
			Console::setCursorPosition(this->x + 0, this->y - 2);
			cout << Console::U2G(n) << Console::U2G(n) << Console::U2G(n);
			Console::setCursorPosition(this->x + 1, this->y - 2);
			cout << Console::U2G(n) << "  " << Console::U2G(n);
		}
		break;
	}
	case 2: {
		if (this->y >= 6) {
			this->clear();
			this->y -= 2;
			Console::setCursorPosition(this->x - 1, this->y - 2);
			cout << "  " << Console::U2G(n) << "  ";
			Console::setCursorPosition(this->x + 0, this->y - 2);
			cout << Console::U2G(n) << Console::U2G(n) << Console::U2G(n);
			Console::setCursorPosition(this->x + 1, this->y - 2);
			cout << Console::U2G(n) << "  " << Console::U2G(n);
		}
		break;
	}
	case 3: {
		if (this->y <= 73) {
			this->clear();
			this->y += 2;
			Console::setCursorPosition(this->x - 1, this->y - 2);
			cout << "  " << Console::U2G(n) << "  ";
			Console::setCursorPosition(this->x + 0, this->y - 2);
			cout << Console::U2G(n) << Console::U2G(n) << Console::U2G(n);
			Console::setCursorPosition(this->x + 1, this->y - 2);
			cout << Console::U2G(n) << "  " << Console::U2G(n);
		}
		break;
	}
	}
	append();
	Console::setColor(black);
}

void TankUser::shoot() {
	bullet[bulletNum % 30] = new  Bullet(this->x - 2, this->y, 0, 1,
		BulletProp::body, BulletProp::attack);
	bullet[bulletNum % 30]->show();
	bulletNum++;
}

void TankUser::bulletMove()
{
	for (int i = 0; i < 30; i++)
	{
		this->bullet[i]->move();
	}
}

int TankUser::isAlive()
{
	if (TankUser::blood <= 0)return false;
	else return true;
}

Bullet** TankUser::getBullet()
{
	return bullet;
}



//TankEnemy
int TankEnemy::selfboom = 1;
TankEnemy::TankEnemy(int x, int y, Color color, int direction, int score, int blood) :Tank(x, y, color, direction)
{
	this->score = score;
	this->blood = blood;
	this->newX = x;
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
			newX += speed;
			this->x = (int)newX;
			Console::setCursorPosition(this->x - 1, this->y - 2);
			cout << Console::U2G(n) << "  " << Console::U2G(n);
			Console::setCursorPosition(this->x + 0, this->y - 2);
			cout << Console::U2G(n) << Console::U2G(n) << Console::U2G(n);
			Console::setCursorPosition(this->x + 1, this->y - 2);
			cout << "  " << Console::U2G(n) << "  ";
		}
		else
		{
			TankUser::blood-= InvincibleProp::selfboom;
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
		x = 2; y = 94;
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

void TankEnemy::isShot()                                                //�жϵ����Ƿ񱻻���
{
	for (int n = 0; n < 100; n++)
	{
		for (int i = this->x - 1; i <= this->x + 1; i++)
		{
			for (int j = this->y - 2; j <= this->y + 3; j++)
			{
				if (Map::map[i][j][0] == 3)
				{
					this->blood -= BulletProp::attack;
					break;
				}
			}
		}
	}
}

int TankEnemy::isAlive()
{
	for (int i = this->x - 1; i <= this->x + 2; i++)
	{
		for (int j = this->y - 2; j <= this->y + 3; j++)
		{
			int bre = 0;
			if (Map::map[i][j][0] == 3)
			{
				blood -= BulletProp::attack;
				bre = 1;
				append();
				Map::map[this->x + 2][this->y - 2][0] = 4;
				Map::map[this->x + 2][this->y - 1][0] = 4;
				Map::map[this->x + 2][this->y - 0][0] = 4;
				Map::map[this->x + 2][this->y + 1][0] = 4;
				Map::map[this->x + 2][this->y + 2][0] = 4;
				Map::map[this->x + 2][this->y + 3][0] = 4;
				break;
			}
			if (bre)break;
		}
	}
	for (int i = this->x - 1; i <= this->x + 2; i++) {
		for (int j = this->y - 2; j <= this->y + 3; j++) {
			if (Map::map[i][j][0] == 2) {
				Alive = 0;
				TankUser::blood -= InvincibleProp::selfboom;
				break;
			}
		}
	}
	if (blood <= 0||Alive==0) { 
		Alive = 0; 
		TankUser::score += this->score; 
		Map::map[this->x + 2][this->y - 2][0] = 0;
		Map::map[this->x + 2][this->y - 1][0] = 0;
		Map::map[this->x + 2][this->y - 0][0] = 0;
		Map::map[this->x + 2][this->y + 1][0] = 0;
		Map::map[this->x + 2][this->y + 2][0] = 0;
		Map::map[this->x + 2][this->y + 3][0] = 0;
	}
	if (!Alive) {
		clear();
		Console::setColor(color);
		Console::setCursorPosition(1, 92);
		cout << "  " << Console::U2G(n) << "  ";
		Console::setCursorPosition(2, 92);
		cout << Console::U2G(n) << Console::U2G(n) << Console::U2G(n);
		Console::setCursorPosition(3, 92);
		cout << Console::U2G(n) << "  " << Console::U2G(n);
		Console::setColor(black);
	}
	return Alive;
}


//�з�̹��Ⱥ
TankEnemies::TankEnemies()                //���캯�����趨��ʼ����
{
	enemies[0] = new TankEnemy(2, 20, green, 1);
	enemies[0]->show(); enemies[0]->append();
	enemies[1] = new TankEnemy(2, 40, red, 1, 10000, 2);
	enemies[1]->show(); enemies[1]->append();
	enemies[2] = new TankEnemy(2, 60, red, 1, 10000, 2);
	enemies[2]->show(); enemies[2]->append();
}

TankEnemies::~TankEnemies() { }

void TankEnemies::allEnemyMove()
{
	for (int i = 0; i <= 2; i++)
	{
		if (this->enemies[i]->isAlive() == 0) {
			Color color = red; int blood = 2; int score = 10000;
			if (Console::Random(1, 3) > 1)
			{
				color = green;
				blood = 1;
				score = 5000;
			}
			this->enemies[i] = new TankEnemy(2, Console::Random(4, 73),color,1,score,blood);
			this->enemies[i]->show(); 
			this->enemies[i]->append();
		}
	}
	for (size_t i = 0; i <= 2; i++)
	{
		this->enemies[i]->move();
	}

}

