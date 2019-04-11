#pragma once							//统筹游戏运行
#ifndef _CONTROL_H
#define _CONTROL_H

#include<iostream>	
using namespace std;
#include"Console.h"

class Control
{
public:
	Control(int _flag=0);
	~Control();
	int start();				//主程序开始
private:
	int flag;
};


#endif // !_CONTROL_H

