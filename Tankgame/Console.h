#pragma once
#ifndef _CONSOLE_H
#define _CONSOLE_H
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //��Ҫ�� 

#include<iostream>
#include <locale>
#include <codecvt>
#include <windows.h> 
using namespace std;

class Console											//����̨��,�����޸Ŀ���̨�������
{
public:
	Console();											//������������ʼ������:��160�Ϳ�50
	~Console();
	static char* U2G(char* utf8);						//utf-8ת����GBK���
	void setCursorPosition(const int x, const int y);	//���ù��λ��
	void setCursorSee(bool _flag);						//��ʾ�����ع��
	void setColor(int number);							//�ı�����򱳾���ɫ
	int checkKey(char key);								//���ĳ�������Ƿ��£����¾͸ı������ɫ
private:

};


#endif // !_CONSOLE_H

