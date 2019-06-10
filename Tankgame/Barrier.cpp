#include<iostream>
#include"Console.h"
#include"Map.h"
#include"Barrier.h"
using namespace std;

//Barrier
Barrier::Barrier(){ }
Barrier::~Barrier(){ }

//River
River::River()
{
    this->x =0;
    this->y =0;
    this->color = 9;
    this->xlen = 3;
    this->ylen = 12;
    this->id = 6;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            this->body[i][j] = 0;
        }
    }
}
River::~River(){ }

void River::show()
{
    char*n = u8"■";
    int a = Console::Random(0, 3)%3 + 1;       //产生1~3之间的随机数
    switch (a)
    {
    case 1:
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                this->body[i][j] = this->Body[0][i][j];
            }
        }
    }
    case 2:
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                this->body[i][j] = this->Body[1][i][j];
            }
        }
    }
    case 3:
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                this->body[i][j] = this->Body[2][i][j];
            }
        }
    }
    }
    Console::setColor(this->color);
    for (int i = 0; i < this->xlen; i++)                    //输出body
    {
        for (int j = 0; j < this->ylen; j += 2)
        {
            Console::setCursorPosition(this->x + i, this->y + j);
            if (this->body[i][j] == 1)
            {
                cout << Console::U2G(n);
            }
        }
    }
    Console::setColor(white);
}

void River::append()              //添加进地图
{
    for (int i = 0; i < this->xlen; i++)
    {
        for (int j = 0; j < this->ylen; j++)
        {
            if (this->body[i][j] == 1)
                Map::map[this->x + i][this->y + j][0] = this->id;
        }
    }
}

//Wall
Wall::Wall()
{
    this->x =0;
    this->y =0;
    this->color = 15;
    this->xlen = 3;
    this->ylen = 10;
    this->id = 1;
}

Wall::Wall(int x,int y)
{
    this->x = x;
    this->y = y;
    this->color = 15;
    this->xlen = 3;
    this->ylen = 10;
    this->id = 1;
}

Wall::~Wall(){ }

void Wall::show()                //在地图上显示
{
    char*n = u8"■";
    Console::setColor(this->color);
    for (int i = 0; i < this->xlen; i++)
    {
        for (int j = 0; j < this->ylen; j += 2)
        {
            Console::setCursorPosition(this->x + i, this->y + j);
            if (this->body[i][j] == 1)
            {
                cout << Console::U2G(n);
            }
        }
    }
}

void Wall::append()            //添加进地图
{
        for (int i = 0; i < this->xlen; i++)
        {
            for (int j = 0; j < this->ylen; j++)
            {
                if (this->body[i][j] == 1)
                    Map::map[this->x + i][this->y + j][0] = this->id;
            }
        }
}

//Brick
Brick::Brick()
{
    this->x = 15;
    this->y = 30;
    this->color = 12;
    this->xlen = 8;
    this->ylen = 22;
    this->id = 7;
}

Brick::~Brick(){ }

void Brick::show()                //地图上显示
{
    char*n = u8"■";
    Console::setColor(this->color);
    for (int i=0; i < this->xlen; i++)
    {
        for (int j = 0; j < this->ylen; j+=2)
        {
            Console::setCursorPosition(this->x + i, this->y + j);
            if (this->body[i][j] == 1)
            {
                cout << Console::U2G(n);
            }
        }
    }
    Console::setColor(white);
}

void Brick::append()              //添加进地图
{
    for (int i = 0; i < this->xlen; i++)
    {
        for (int j = 0; j < this->ylen; j++)
        {
            if (this->body[i][j] == 1)
                Map::map[this->x + i][this->y + j][0] = this->id;
            else Map::map[this->x + i][this->y + j][0] = 0;
        }
    }
}

void Brick::iShot()               //判断击中及击中后的改变
{
    for (int i = 0; i < this->xlen; i++)
    {
        for (int j = 0; j < this->ylen; j++)
        {
            if (Map::map[this->x + i][this->y + j][0] == 3)           //如果遇到子弹则被击碎
                Map::map[this->x + i][this->y + j][0] = 0;
        }
    }
    char*n = u8"■";
    for (int i = 0; i < xlen; i++)
    {
        for (int j = 0; j < ylen; j += 2)
        {
            if (Map::map[this->x + i][this->y + j][0] == this->id)                //没被击碎刷新输出
            {
                Console::setCursorPosition(x + i, y + j);
                Console::setColor(this->color);
                cout << Console::U2G(n);
            }
           // else if (Map::map[this->x + i][this->y + j][0] == 0) cout << "  ";        //被击碎后输出空格
           
        }
    }
    Console::setColor(white);
}

//barries
barries::barries(){ }
barries::~barries(){ }

void barries::initBarries()               //初始化障碍物
{
    b1 = new Brick();
    b1->show();
    b1->append();
    r1 = new River();
    r1->x = Console::Random(21, 25);
    r1->y = Console::Random(54, 62);
    r1->show();
    r1->append();
    r2 = new River();
    r2->x = Console::Random(5, 10);
    r2->y = Console::Random(16, 62);
    r2->show();
    r2->append();
    w1 = new Wall(14,68);
    w1->show();
    w1->append();
    w2 = new Wall(7,2);
    w2->show();
    w2->append();
    w3 = new Wall();
    w3->x = Console::Random(16, 25);
    w3->y = Console::Random(2, 16);
    w3->show();
    w3->append();
}

void barries::refresh()           //刷新障碍物
{
    this->b1->iShot();
    this->r1->append();
    this->r1->show();
    this->r2->append();
    this->r2->show();
    this->w1->append();
    this->w1->show();
    this->w2->append();
    this->w2->show();
    this->w3->append();
    this->w3->show();
}