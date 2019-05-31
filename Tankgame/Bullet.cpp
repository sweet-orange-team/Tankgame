#include"Tank.h"
#include"Console.h"
#include"Bullet.h"
#include"Map.h"
using namespace std;

Bullet::Bullet(int x, int y, int dir, int isSee, char* body, int attack)                            //��ʼ���ӵ�����
{
    this->x = x;
    this->y = y;
    this->direction = dir;
    this->isSee = isSee;
    this->body = body;
    this->attack = attack;
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
void Bullet::append()								//�ڵ�ͼ�ϸ����ӵ�
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
        if (this->x >= step * 2 && (this->x != 1 && this->y != 90)) {
            this->x -= step;				//��ǰԤ����һ���ִ�㣬�ӵ���������
            append();						//��ӽ���ͼ
            clear();						//�������Ļ�ϵ���ʾ
            if (Map::map[x][y][0] == 4 || Map::map[x][y + 1][0] == 4 || Map::map[x][y][0] ==
                7 || Map::map[x][y + 1][0] == 7 || Map::map[x][y][0] == 1 || Map::map[x][y +
                1][0] == 1) 				//�жϸõִ����û�ез�̹��
            {
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
        break;
    case 1:
        Map::map[this->x][this->y][0] = 0;
        if (this->x <= 29 - step * 2 && (this->x != 1 && this->y != 90)) {
            this->x += step;						//��ǰԤ����һ���ִ�㣬�ӵ���������
            append();								//��ӽ���ͼ
            clear();								//�������Ļ�ϵ���ʾ
            if (Map::map[x][y][0] == 4 || Map::map[x][y + 1][0] == 4 || Map::map[x][y][0]
                == 7 || Map::map[x][y + 1][0] == 7 || Map::map[x][y][0] == 1 || Map::map[x]
                [y + 1][0] == 1)
            {
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

        break;
    case 2:
        Map::map[this->x][this->y][0] = 0;
        if (this->y >= (step * 2 + 2) && (this->x != 1 && this->y != 90)) {
            this->y -= step * 2;
            append();
            clear();
            if (Map::map[x][y][0] == 4 || Map::map[x][y][0] ==
                7 || Map::map[x][y][0] == 1)
            {
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
        break;
    case 3:
        Map::map[this->x][this->y][0] = 0;
        if (this->y < (77 - step * 2) && (this->x != 1 && this->y != 90)) {
            this->y += step * 2;
            append();
            clear();
            if (Map::map[x][y][0] == 4 || Map::map[x][y][0] ==
                7 || Map::map[x][y][0] == 1) 	//�жϸõִ����û�ез�̹��
            {
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