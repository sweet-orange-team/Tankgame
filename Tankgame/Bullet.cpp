#include"Tank.h"
#include"Console.h"
#include"Bullet.h"
using namespace std;
Tank a;
Bullet::Bullet(int x,int y)                            //初始化子弹属性
{
	this->x = x;
	this->y = y;
}
Bullet::~Bullet() { }
void Bullet:: append(Map &Map)                                                         //在屏幕上显示子弹
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            //Map.map[this->x + i][this->y + j][0] = this->body[i][j];
            Map.map[this->x + i][this->y + j][1] = color;
        }
    }
}

void Bullet::move()                                                  //子弹移动
{
    
}

char * Bullet::body()
{
	return Console::U2G(this->body);
}

