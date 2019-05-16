#include"Tank.h"
#include"Console.h"
#include"ctime"
#include"Bullet.h"
#include"Map.h"
using namespace std;


//����
Tank::Tank(int x, int y, Color color, int direction)
{
    this->color = color;
    this->direction = direction;
    this->x = x;
    this->y = y;
}

Tank::~Tank(){ }

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
    for (int i = -1; i <= 1; i++) {
        for (int j = -2; j <= 3; j++) {
            Map::map[x + i][y + j][0] = 0;
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
int TankUser::attack = 1;
TankUser::TankUser(int x, int y,  Color color, int direction) :Tank(x, y, color, direction)          //���캯������ʼ��̹��Ĭ�ϲ���
{
	this->color = color;
	this->direction = direction;
	this->blood = blood;
	this->speed = speed;
	this->armour = armour;
    this->attack = attack;
	this->x = x;
	this->y = y;
	append();
    for (int i = 0; i < 100; i++)
    {
        bullet[i] = new Bullet(0, 0, 0);
    }
	//bullet1=new Bullet(0,0,0);
	//bullet2=new Bullet(0,0,0);
	//bullet3=new Bullet(0,0,0);
	//bullet4=new Bullet(0,0,0);
	//bullet5=new Bullet(0,0,0);
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

void TankUser::shoot() {

    switch (direction)
    {
    case 0:
    {
        bullet[bulletNum%100] = new  Bullet(this->x - 2, this->y, 0); bullet[bulletNum % 100]->show();
        bulletNum++;
        break;

           // switch (bulletNum % 5)
           // {
           // case 0: bullet1 = new  Bullet(this->x - 2, this->y, 0); (*bullet1).show(); break;
           // case 1: bullet2 = new  Bullet(this->x - 2, this->y, 0); (*bullet2).show(); break;
           // case 2: bullet3 = new  Bullet(this->x - 2, this->y, 0); (*bullet3).show(); break;
           // case 3: bullet4 = new  Bullet(this->x - 2, this->y, 0); (*bullet4).show(); break;
           // case 4: bullet5 = new  Bullet(this->x - 2, this->y, 0); (*bullet5).show(); break;
           // default:
           //     break;
           // }
    }
    default:
        break;
    }
}

void TankUser::bulletMove()
{
    for (int i = 0; i < 100; i++)
    {
        this->bullet[i]->move();
    }

	//(*bullet1).move();
	//(*bullet2).move();
	//(*bullet3).move();
	//(*bullet4).move();
	//(*bullet5).move();
}

int TankUser::isAlive()
{
	if (TankUser::blood == 0)return false;
	else return true;
}

Bullet** TankUser::getBullet()
{
    return bullet;
}

//TankEnemy

int TankEnemy::selfboom = 1;

TankEnemy::TankEnemy(int x , int y , Color color , int direction,int score, int blood ):Tank(x,y,color,direction)
{
	this->score = score;
    this->blood = blood;
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
			TankUser::blood--;
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

void TankEnemy::isShot(TankUser&Tank)                                                //�жϵ����Ƿ񱻻���
{
    for (int n = 0; n < 100; n++)
    {
        for (int i = this->x - 1; i <= this->x + 2; i++) {
            for (int j = this->y - 2; j <= this->y + 3; j++) {
                if (Map::map[i][j][0] == 3) {
                    this->blood-=Tank.attack; 
                }
            }
        }
        //for (int i = -1; i < 2; i++)
        //{
        //    for (int j = -2; j < 4; j++)
        //    {
        //        if ( (Tank.getBullet()[n]->getX()== this->getX() + i) || (Tank.getBullet()[n]->getX() + 1 == Tank.getX() + i) && (Tank.getBullet()[n]->getY()==this->getY() + j)) this->blood--;
        //    }
        //}
    }
}

int TankEnemy::isAlive()
{
	//for (int i = this->x - 1; i <= this->x + 2; i++) {
	//	for (int j = this->y - 2; j <= this->y + 3; j++) {
	//		if (Map::map[i][j][0] == 3) { 
	//			Alive = 0; TankUser::score += this->score; break;
	//		}
    for (int i = this->x - 1; i <= this->x + 2; i++) {
        for (int j = this->y - 2; j <= this->y + 3; j++) {
            if (Map::map[i][j][0] == 2) {
                Alive = 0; TankUser::blood-=this->selfboom; break;
            }
        }
    }
    if (blood == 0)Alive = 0;

	return Alive;
}
