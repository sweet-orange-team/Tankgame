#include"Tank.h"
#include"Console.h"
#include"ctime"
using namespace std;

//¼º·½Ì¹¿Ë
Tank_Users::Tank_Users(int id, int blood, int armour, int speed, Color color, int direction) :Tank(blood, armour, speed, color, direction) {
    this->identification = id;
}

Tank_Users::~Tank_Users() { }

int Tank_Users::getID() {
    return this->identification;
}

