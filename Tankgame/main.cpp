#include<iostream>
#include <stdio.h> 
#include <windows.h>
using namespace std;
#include"Console.h"
#include"Control.h"
#include"Map.h"

int main() {
	Console console;				//��ʼ������̨
	Map map;
	map.showmap();
	system("pause");
	return 0;
}