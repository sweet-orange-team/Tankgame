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
    void tankl(int, int);
    void tankr(int, int);
    void clear(int, int);
    void animation();           //��ͷ����
    int menu();                 //�˵�
	int start();				//����Ϸѭ����ʼ
	int restart();				//���¿�ʼ��Ϸ
private:
	int flag;
};


#endif // !_CONTROL_H

