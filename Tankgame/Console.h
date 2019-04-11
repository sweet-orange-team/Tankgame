#pragma once
#ifndef _CONSOLE_H
#define _CONSOLE_H
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //必要的 

#include<iostream>
#include<string>
#include<cstring>
#include <stdio.h> 
#include <windows.h> 
using namespace std;

class Console										//控制台类,用于修改控制台各项参数
{
public:
	Console();
	~Console();
	void cursorPosition(const int x, const int y);	//设置光标位置
	void cursorSee(bool _flag);						//显示或隐藏光标
	void setColor(char flag);
	void color(int a);								//改变输出的颜色，比system("color x")快得多
	int check(char c);								//检测某个按键是否按下，按下就改变输出颜色
private:

};


#endif // !_CONSOLE_H

