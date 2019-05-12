#include"Tank.h"
#include"Console.h"
#include"Bullet.h"
using namespace std;
Tank a;
Bullet::Bullet(int harm = 2, int speed = 2, Color col = white, Tank&tank = a)                            //初始化子弹属性
{
    this->harm = harm;
    this->speed = speed;
    this->color = col;
    this->direction = tank.getDir();
    /*switch (this->direction) {
    case 0:this->x = tank.getX() - 3;
    case 1:this->x = tank.getX() + 3;
    case 2:this->y = tank.getY() - 6;
    case 3:this->y = tank.getY() + 6;
    }*/
}
Bullet::~Bullet() { }
//void Bullet:: append(Map &Map)                                                         //在屏幕上显示子弹
//{
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 6; j++) {
//            Map.map[this->x + i][this->y + j][0] = this->body[i][j];
//            Map.map[this->x + i][this->y + j][1] = color;
//        }
//    }
//}

void Bullet::move(Map& Map,Tank&Tank)                                                  //子弹移动
{
    int d = Tank.getDir();
    switch (d)
    {
    case 0: 
    {
        x -= 1;
        append(Map);
    }
    case 1: 
    {
        x += 1;
        append(Map);
    }
    case 2: 
    {
        y -= 2;
        append(Map);
    }
    case 3: 
    {
        y += 2;
        append(Map);
    }
    }
}