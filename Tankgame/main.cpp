#include<iostream>
#include <stdio.h> 
#include <windows.h>
using namespace std;
#include"Console.h"


int main() {
	Console console;				//初始化控制台

	cout << "11111" << endl;
	console.setColor('r');
	cout << "22222" << endl;
	console.color(14);
	cout << "33333" << endl;

	system("pause");
	return 0;
}