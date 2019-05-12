#include"Tank.h"
#include"Console.h"
#include"ctime"
using namespace std;

//�з�̹��
Tank_Enemies::Tank_Enemies(int id, int blood, int armour, int speed, Color color, int direction) :Tank(blood, armour, speed, color, direction)                 //���캯�����趨��ʼ����
{
    this->identification = id;
}

Tank_Enemies::~Tank_Enemies() { }

int Tank_Enemies::getID() 
{
    return this->identification;
}



//��ͨ����
Tank_Ordinary::Tank_Ordinary(int id, int blood, int armour, int speed, Color color, int direction) :Tank_Enemies(id, blood, armour, speed, color, direction) 
{
    if (rand() % 2) color = white;
    else color = gray;
}

Tank_Ordinary::~Tank_Ordinary() { }



//BOSS
Tank_Boss::Tank_Boss(int id, int blood, int armour, int speed, Color color, int direction) : Tank_Enemies(id, blood, armour, speed, color, direction) 
{
    if (rand() % 2) color = red;
    else color = pink;
}

Tank_Boss::~Tank_Boss() { }