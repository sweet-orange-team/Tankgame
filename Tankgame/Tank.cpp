#include"Tank.h"
#include"Console.h"
#include"ctime"
using namespace std;


//基类

Tank::Tank(int x, int y, int blood, int armour, int speed, Color color, int direction)                                //构造函数，初始化坦克默认参数
{
	this->color = color;
	this->direction = direction;
	this->blood = blood;
	this->speed = speed;
	this->armour = armour;
	this->x = x;
	this->y = y;
}


Tank::~Tank()
{
}

int Tank::getDir()                                                                                         //返回坦克方向
{
	return direction;
}

int Tank::getX()
{
	return this->x;
}

int Tank::getY()
{
	return this->y;
}



void Tank::append(Map& Map)                                                                                 //在地图上输出坦克 
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			Map.map[this->x + i][this->y + j][0] = this->body[this->direction][i][j];
			Map.map[this->x + i][this->y + j][1] = color;
		}
	}
}

void Tank::append(Map &Map, int a, int b)                                                                    //重载
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			Map.map[a + i][b + j][0] = this->body[this->direction][i][j];
			Map.map[a + i][b + j][1] = color;
		}
	}
}

void Tank::move(int d)                                                                              //移动坦克
{
	Console::setColor(yellow);
	this->direction = d;
	char* n = u8"■";

	switch (d) {
	case 0: {
		if (this->x >= 3) {
			for (int i = -1; i <= 1; i++) {
				Console::setCursorPosition(this->x + i, this->y - 2);
				cout << "      ";
			}
			this->x -= 1;
			Console::setCursorPosition(this->x - 1, this->y-2);
			cout << "  " << Console::U2G(n) << "  ";
			Console::setCursorPosition(this->x + 0, this->y-2);
			cout << Console::U2G(n) << Console::U2G(n) << Console::U2G(n);
			Console::setCursorPosition(this->x + 1, this->y-2);
			cout << Console::U2G(n) << "  " << Console::U2G(n);
		}
		break;
	}
	case 1: {
		if (this->x <= 26) {
			for (int i = -1; i <= 1; i++) {
				Console::setCursorPosition(this->x + i, this->y - 2);
				cout << "      ";
			}
			this->x += 1;
			Console::setCursorPosition(this->x - 1, this->y-2);
			cout << Console::U2G(n) << "  " << Console::U2G(n);
			Console::setCursorPosition(this->x + 0, this->y-2);
			cout << Console::U2G(n) << Console::U2G(n) << Console::U2G(n);
			Console::setCursorPosition(this->x + 1, this->y-2);
			cout << "  " << Console::U2G(n) << "  ";
		}
		break;
	}
	case 2: {
		if (this->y >= 6) {
			for (int i = -1; i <= 1; i++) {
				Console::setCursorPosition(this->x + i, this->y - 2);
				cout << "      ";
			}
			this->y -= 2;
			Console::setCursorPosition(this->x - 1, this->y - 2);
			cout << "  " << Console::U2G(n) << Console::U2G(n);
			Console::setCursorPosition(this->x + 0, this->y - 2);
			cout << Console::U2G(n) << Console::U2G(n)<< "  " ;
			Console::setCursorPosition(this->x + 1, this->y - 2);
			cout << "  " << Console::U2G(n) << Console::U2G(n);
		}
		break;
	}
	case 3: {
		if (this->y <= 73) {
			for (int i = -1; i <= 1; i++) {
				Console::setCursorPosition(this->x + i, this->y - 2);
				cout << "      ";
			}
			char* n = u8"■";
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
	Console::setColor(black);
}

//todo 用Bullet替代字符
void Tank::shoot(){
	char *n = u8"◆";
	switch (this->direction)
	{
	case 0:
		Console::setCursorPosition(this->x - 2, this->y);
		cout << Console::U2G(n);
	default:
		break;
	}
}


