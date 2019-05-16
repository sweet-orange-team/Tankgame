#pragma once
#ifndef _CONSOLE_H
#define _CONSOLE_H
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //必要的,来检测按键 

#include<iostream>
#include <locale>
#include <codecvt>
#include <windows.h> 
using namespace std;
#include"Tank.h"


class Console											//控制台类,用于修改控制台各项参数
{
public:
	Console();											//以内置条件初始化窗口:长160和宽50
	~Console();
	static char* U2G(char* utf8);						//utf-8转换到GBK输出
	static void setCursorPosition(const int x, const int y);	//设置光标位置
	static void setCursorSee(bool _flag);						//显示或隐藏光标
	static void setColor(int number);							//改变字体或背景颜色
	static void checkKey(TankUser &mytank);							//检测某个按键是否按
	HANDLE hOutput, hOutBuf;							//控制台屏幕缓冲区句柄
	COORD coord = { 0,0 };
	//双缓冲处理显示
	DWORD bytes = 0;	
};


#endif // !_CONSOLE_H

