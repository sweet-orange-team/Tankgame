#pragma once
#ifndef _CONSOLE_H
#define _CONSOLE_H
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //��Ҫ��,����ⰴ�� 

#include<iostream>
#include <locale>
#include <codecvt>
#include <windows.h> 
using namespace std;
#include"Tank.h"


class Console											//����̨��,�����޸Ŀ���̨�������
{
public:
	Console();											//������������ʼ������:��160�Ϳ�50
	~Console();
	static char* U2G(char* utf8);						//utf-8ת����GBK���
	static void setCursorPosition(const int x, const int y);	//���ù��λ��
	static void setCursorSee(bool _flag);						//��ʾ�����ع��
	static void setColor(int number);							//�ı�����򱳾���ɫ
	static void checkKey(TankUser &mytank);						//���ĳ�������Ƿ�
	static int Random(int a, int b);	
};


#endif // !_CONSOLE_H

