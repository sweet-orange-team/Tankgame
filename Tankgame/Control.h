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
    static int j,a;
    int menu();                 //�˵�
    void tankl(int,int);
    void tankr(int,int);
    void clear(int,int);
    void animation();
    int init();
	int start();				//������ʼ
private:
	int flag;
};


#endif // !_CONTROL_H

