#pragma once
#ifndef _CONSOLE_H
#define _CONSOLE_H
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //��Ҫ�ģ����Ǳ������� 

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
	void cursorPosition(const int x, const int y);//���ù��λ��
	void cursorSee(bool _flag);					//��ʾ�����ع��
	void setColor(char flag);
	void color(int a);							//�ı��������ɫ����system("color x")��ö�
	int check(char c);							//���ĳ�������Ƿ��£����¾͸ı������ɫ
private:

};


#endif // !_CONSOLE_H

