#include<iostream>
#include"Console.h"
#include"Map.h"
#include"Prop.h"
#include"Tank.h"
#include"Barrier.h"
#include"windows.h"
#include"Control.h"
#include<conio.h>
using namespace std;

//Barrier
Barrier::Barrier(){ }
Barrier::~Barrier(){ }

//River
int River::a = 0;
River::River()
{
    this->x = Console::Random(5, 22);
    this->y = Console::Random(2, 70);
    this->color = 9;
    this->xlen = 3;
    this->ylen = 8;
    this->id = 6;
}
River::~River(){ }

void River::show()
{
    char*n = u8"��";
    a = Console::Random(0, 3)%3 + 1;
    switch (a)
    {
    case 1:
    {
        Console::setColor(this->color);
        Console::setCursorPosition( this->x , this->y );
        cout << "  " << "  " << Console::U2G(n);// << "  ";
        Console::setCursorPosition(this->x + 1, this->y );
        cout << "  " << Console::U2G(n) << Console::U2G(n) << Console::U2G(n);
        Console::setCursorPosition(this->x + 2, this->y);
        cout << Console::U2G(n) << Console::U2G(n);// << "  " << "  ";
        Console::setColor(white);
    }
    case 2:
    {
        Console::setColor(this->color);
        Console::setCursorPosition(this->x, this->y);
        cout  << "  " << Console::U2G(n) ;
        Console::setCursorPosition(this->x + 1, this->y);
        cout  << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) ;
        Console::setCursorPosition(this->x + 2, this->y);
        cout  << "  " << "  " << Console::U2G(n) << Console::U2G(n);
        Console::setColor(white);
    }
    case 3:
    {
        Console::setColor(this->color);
        Console::setCursorPosition(this->x, this->y);
        cout << "  " << Console::U2G(n)<<"  "<<"  " ;
        Console::setCursorPosition(this->x + 1, this->y);
        cout << Console::U2G(n) << Console::U2G(n) <<"  "<<"  ";
        Console::setCursorPosition(this->x + 2, this->y);
        cout << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << Console::U2G(n);
        Console::setColor(white);
    }
    }
}

void River::append()
{
    for (int i = 0; i < this->xlen; i++)
    {
        for (int j = 0; j < this->ylen; j++)
        {
            if (this->body[a][i][j]==1)
                Map::map[this->x + i][this->y + j][0] = this->id;
        }
    }
}

//Wall
Wall::Wall()
{
    this->x = Console::Random(5, 23);
    this->y = Console::Random(2, 72);
    this->color = 15;
    this->xlen = 2;
    this->ylen = 6;
    this->id = 1;
}

Wall::Wall(int x,int y)
{
    this->x = x;
    this->y = y;
    this->color = 15;
    this->xlen = 2;
    this->ylen = 6;
    this->id = 1;
}

Wall::~Wall(){ }

void Wall::show()
{
    char*n = u8"��";
    Console::setColor(this->color);
    Console::setCursorPosition(this->x, this->y);
    cout << Console::U2G(n) << Console::U2G(n) << Console::U2G(n);
    Console::setCursorPosition(this->x+1, this->y);
    cout << Console::U2G(n) << Console::U2G(n);//<<"  ";
    Console::setColor(white);
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
    char*n = u8"��";
    Console::setColor(this->color);
    Console::setCursorPosition(this->x, this->y);
    cout << "  " << "  " << "  " << "  " << Console::U2G(n) << "  " << Console::U2G(n); //<< "  " << "  " << "  " << "  ";
    Console::setCursorPosition(this->x + 1, this->y);
    cout << "  " << "  " << "  " << "  " << Console::U2G(n) << "  " << Console::U2G(n); //<< "  " << "  " << "  " << "  ";
    Console::setCursorPosition(this->x + 2, this->y);
    cout << Console::U2G(n) << "  " << "  " << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << "  " << "  " << Console::U2G(n);
    Console::setCursorPosition(this->x + 3, this->y);
    cout << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << "  " << Console::U2G(n) <<"  " << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << Console::U2G(n);
    Console::setCursorPosition(this->x + 4, this->y);
    cout << "  " << "  " << "  " << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << Console::U2G(n); //<< "  " << "  " << "  ";
    Console::setCursorPosition(this->x + 5, this->y);
    cout << "  " << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << Console::U2G(n);//<< "  ";
    Console::setCursorPosition(this->x + 6, this->y);
    cout << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << "  " << Console::U2G(n) << Console::U2G(n) << Console::U2G(n) << "  " << Console::U2G(n) << Console::U2G(n) << Console::U2G(n);
    Console::setCursorPosition(this->x + 7, this->y);
    cout << Console::U2G(n) << Console::U2G(n)<< "  " << "  " << "  "  << Console::U2G(n)  << "  " << "  " << "  "<< Console::U2G(n) << Console::U2G(n);
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
        }
    }
}

void Brick::iShot()
{
        for (int i = this->x+xlen; i >= this->x ; i--)
        {
            for (int j = this->y; j <= this->y + 9; j++)
            {
                if (Map::map[i][j][0] == 3)
                {
                    Console::setCursorPosition(i-1, j);
                    cout << "  ";
                    Map::map[i][j][0] = 0;
                    break;
                }
            }
        }
}

//barries
barries::barries(){ }
barries::~barries(){ }

void barries::initBarries()
{
    r1 = new River();
    r1->show();
    r1->append();
    r2 = new River();
    r2->show();
    r2->append();
    w1 = new Wall(10,37);
    w1->show();
    w1->append();
    w2 = new Wall(7,2);
    w2->show();
    w2->append();
    w3 = new Wall(16,72);
    w3->show();
    w3->append();
    b1 = new Brick();
    b1->show();
    b1->append();
}