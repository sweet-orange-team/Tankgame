#include<iostream>
#include <stdio.h> 
#include <windows.h>
using namespace std;
#include"Console.h"
#include"Control.h"
#include"Map.h"
#include"Tank.h"

int main() {
	Console console;				//��ʼ������̨
	Map map;						//��ʼ����ͼ
	map.show();						//�����ͼ
	Tank tank;
	tank.append(map);
	map.show();
	system("pause");
	return 0;
}