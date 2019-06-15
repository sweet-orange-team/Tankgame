#pragma once					//统筹游戏运行
#ifndef _CONTROL_H
#define _CONTROL_H

#include<iostream>	
#include"Console.h"
using namespace std;

class Control
{
public:
	Control(int _flag=0);
	~Control();
    void tankl(int, int);
    void tankr(int, int);
    void clear(int, int);
    void animation();           //开头动画
    int menu();                 //菜单
	int start();				//主游戏循环开始
	int restart();				//重新开始游戏
private:
	int flag;
};


#endif // !_CONTROL_H

