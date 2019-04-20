#include"Tank.h"
#include"Console.h"

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

