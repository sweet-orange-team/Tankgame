#pragma once							//ͳ����Ϸ����
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
	int start();				//������ʼ
private:
	int flag;
};


#endif // !_CONTROL_H

