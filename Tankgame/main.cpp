#include<iostream>
#include <stdio.h> 
#include <windows.h>
using namespace std;
#include"Console.h"


int main() {
	Console console;				//初始化控制台
	cout << "hello-------------------------------------------------------------------------------\n";	//测试
	while (1) {
		if (console.check('Q')) {
			cout << "你好啊！" << endl;
		};
		Sleep(20);//循环时间间隔，防止太占内存
		//system("cls");//清屏 
	}
	

	system("pause");
	return 0;
}