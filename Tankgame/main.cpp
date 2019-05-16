#include"Console.h"
#include"Control.h"
#include"Map.h"
#include"Tank.h"
int main() {
	Control control;
    if (control.menu() == -1)return 0;
    else control.start();
}
/*
int Random(int a, int b)   //产生一个[a,b)上的整数
{
    int c = (rand() % (a - b)) + a;
    return c;
}
*/
//不知道放在哪里 哈哈哈哈