#pragma once
#ifndef _CONSOLE_H
#define _CONSOLE_H
#include<iostream>				//��һҳ���Ǳ���.............�����ܵ�ͨ��������
#include<string>
#include<cstring>
#include <stdio.h> 
#include <windows.h> 
using namespace std;

class Console		//����̨��,�����޸Ŀ���̨�������
{
public:
	Console(const char* const &name = "ͼ�����ϵͳ-by charon and Yvein");
	~Console();
	void cursor(bool _flag);									//��ʾ�����ع��
	void setColor(char flag);

private:

};


#endif // !_CONSOLE_H

