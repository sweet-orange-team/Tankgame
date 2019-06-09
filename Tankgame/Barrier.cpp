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
    this->judge = 1;
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
    char*n = u8"¡ö";
    int a = Console::Random(0, 3)%3 + 1;
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
    Console::setColor(white);
}

void River::append()
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
    this->judge = 1;
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

void Wall::show()
{
    char*n = u8"¡ö";
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

void Wall::append()
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
int Brick::a = 0;
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

void Brick::show()
{
    char*n = u8"¡ö";
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

void Brick::append()
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

void Brick::iShot()
{
    for (int i = 0; i < this->xlen; i++)
    {
        for (int j = 0; j < this->ylen; j++)
        {
            if (Map::map[this->x + i][this->y + j][0] == 3)
                Map::map[this->x + i][this->y + j][0] = 0;
        }
    }
    char*n = u8"¡ö";
    for (int i = 0; i < xlen; i++)
    {
        for (int j = 0; j < ylen; j += 2)
        {
            if (Map::map[this->x + i][this->y + j][0] == this->id)
            {
                Console::setCursorPosition(x + i, y + j);
                Console::setColor(this->color);
                cout << Console::U2G(n);
            }
            else if (Map::map[this->x + i][this->y + j][0] == 0) cout << "  ";
            Console::setColor(white);
        }
    }
}

//barries
barries::barries(){ }
barries::~barries(){ }

void barries::initBarries()
{
    b1 = new Brick();
    b1->show();
    b1->append();
    r1 = new River();
    r1->x = Console::Random(17, 25);
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

void barries::refresh()
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