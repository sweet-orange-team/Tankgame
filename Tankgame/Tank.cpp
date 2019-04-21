#include"Tank.h"
#include"Console.h"
#include"ctime"
using namespace std;
//基类
Tank::Tank(Color color, int direction, int blood, int speed, int armour) {
	this->color = color;
	this->direction = direction;
	this->blood = blood;
	this->speed = speed;
	this->armour = armour;
}

Tank::~Tank()
{
}

void Tank::append(Map& Map, int x, int y)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			Map.map[x + i][y + j] = this->body[this->direction][i][j];
		}
	}
}
//己方
Tank_Users::Tank_Users(Color color = yellow, int direction = 0, int blood = 100, int speed = 1, int armour = 50, int id = 0) :Tank(color, direction, blood, speed, armour) {
    this->identification = id;
}

Tank_Users::~Tank_Users() { }

int Tank_Users::getID() {
    return this->identification;
}

//敌方
Tank_Enemies::Tank_Enemies(Color color , int direction, int blood , int speed , int armour , int id = 1) :Tank(color, direction, blood, speed, armour) {
    this->identification = id;
}

Tank_Enemies::~Tank_Enemies() { }

int Tank_Enemies::getID() {
    return this->identification;
}

//普通敌人
Tank_Ordinary::Tank_Ordinary( int direction = 0, int blood = 30, int speed = 1, int armour = 10, int id = 1) :Tank_Enemies( color, direction, blood, speed, armour, id ) {
    if (rand() % 2) color = white;        
    else color = gray;
}

Tank_Ordinary::~Tank_Ordinary(){ }

//BOSS
Tank_Boss::Tank_Boss( int direction = 0, int blood = 30, int speed = 1, int armour = 10, int id = 1) : Tank_Enemies(color, direction, blood, speed, armour, id) {
    if (rand() % 2) color = red;        
    else color = pink;
}

Tank_Boss::~Tank_Boss() { }