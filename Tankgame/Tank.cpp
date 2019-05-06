#include"Tank.h"
#include"Console.h"
#include"ctime"
using namespace std;


//基类
Tank::Tank(int blood, int armour, int speed, Color color, int direction) {
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
			Map.map[x + i][y + j][0] = this->body[this->direction][i][j];
			Map.map[x + i][y + j][1] = color;
		}
	}
}


void Tank::move(char c, Map& Map, int x, int y) {
	switch (c) {
	case('W'):
	case('w'): {
		y++;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 6; j++) {
				Map.map[x + i][y + j][0] = this->body[this->direction][i][j];
				Map.map[x + i][y + j][1] = color;
			}
		}
		break;
	}
	case('S'):
	case('s'): {
		y--;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 6; j++) {
				Map.map[x + i][y + j][0] = this->body[this->direction][i][j];
				Map.map[x + i][y + j][1] = color;
			}
		}
		break;
	}
	case('A'):
	case('a'): {
		x--;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 6; j++) {
				Map.map[x + i][y + j][0] = this->body[this->direction][i][j];
				Map.map[x + i][y + j][1] = color;
			}
		}
		break;
	}
	case('D'):
	case('d'): {
		x++;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 6; j++) {
				Map.map[x + i][y + j][0] = this->body[this->direction][i][j];
				Map.map[x + i][y + j][1] = color;
			}
		}
		break;
	}
	}
}


//己方
Tank_Users::Tank_Users(int id, int blood, int armour, int speed, Color color, int direction) :Tank(blood, armour, speed, color, direction) {
	this->identification = id;
}

Tank_Users::~Tank_Users() { }

int Tank_Users::getID() {
	return this->identification;
}



//敌方
Tank_Enemies::Tank_Enemies(int id, int blood, int armour, int speed, Color color, int direction) :Tank(blood, armour, speed, color, direction) {
	this->identification = id;
}

Tank_Enemies::~Tank_Enemies() { }

int Tank_Enemies::getID() {
	return this->identification;
}



//普通敌人
Tank_Ordinary::Tank_Ordinary(int id, int blood, int armour, int speed, Color color, int direction) :Tank_Enemies(id, blood, armour, speed, color, direction) {
	if (rand() % 2) color = white;
	else color = gray;
}

Tank_Ordinary::~Tank_Ordinary() { }



//BOSS
Tank_Boss::Tank_Boss(int id, int blood, int armour, int speed, Color color, int direction) : Tank_Enemies(id, blood, armour, speed, color, direction) {
	if (rand() % 2) color = red;
	else color = pink;
}

Tank_Boss::~Tank_Boss() { }