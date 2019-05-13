#include"Tank.h"
#include"Console.h"
#include"Map.h"
#include"ctime"
using namespace std;

//¼º·½Ì¹¿Ë
Tank_Users::Tank_Users(Map &map,int id, int blood, int armour, int speed, Color color, int direction) :Tank(map,blood, armour, speed, color, direction) {
    this->identification = id;
}

Tank_Users::~Tank_Users() { }

int Tank_Users::getID() {
    return this->identification;
}

