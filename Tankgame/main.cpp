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
int Random(int a, int b)   //����һ��[a,b)�ϵ�����
{
    int c = (rand() % (a - b)) + a;
    return c;
}
*/
//��֪���������� ��������