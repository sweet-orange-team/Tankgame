#pragma once					//ͳ����Ϸ����
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
    int menu();                 //�˵�
	int start();				//������ʼ
private:
	int flag;
};


#endif // !_CONTROL_H

