#include"Tank.h"
#include"Console.h"
#include"ctime"
#include"Control.h"
using namespace std;

//敌方坦克群
Tank_Enemies::Tank_Enemies()                //构造函数，设定初始属性
{
	enemy1 = &TankEnemy(-2,5,pink);
	enemyNum++;
}

Tank_Enemies::~Tank_Enemies() { }

void Tank_Enemies::allEnemyMove()
{
	(*enemy1 ).move();
	(*enemy2 ).move();
	(*enemy3 ).move();
	(*enemy4 ).move();
	(*enemy5 ).move();
}

void Tank_Enemies::del()
{

}

void Tank_Enemies::add()
{
	enemyNum %= 5;
	switch (enemyNum)
	{
	case 0:enemy1 = &TankEnemy( 3, 10, pink); enemy1->show(); break;
	case 1:enemy2 = &TankEnemy( 3, 10, pink); enemy2->show(); break;
	case 2:enemy3 = &TankEnemy( 3, 10, pink); enemy3->show(); break;
	case 3:enemy4 = &TankEnemy( 3, 10, pink); enemy4->show(); break;
	case 4:enemy5 = &TankEnemy( 3, 10, pink); enemy5->show(); break;
	default:
		break;
	}
}
//int Tank_Enemies::getID() 
//{
//    return this->identification;
//}
//
//
//
////普通敌人
//Tank_Ordinary::Tank_Ordinary(Map &map, int id, int blood, int armour, int speed, Color color, int direction) :Tank_Enemies(map, id, blood, armour, speed, color, direction)
//{
//    if (rand() % 2) color = white;
//    else color = gray;
//}
//
//Tank_Ordinary::~Tank_Ordinary() { }
//
//
//
////BOSS
//Tank_Boss::Tank_Boss(Map &map, int id, int blood, int armour, int speed, Color color, int direction) : Tank_Enemies(map, id, blood, armour, speed, color, direction)
//{
//    if (rand() % 2) color = red;
//    else color = pink;
//}
//
//Tank_Boss::~Tank_Boss() { }