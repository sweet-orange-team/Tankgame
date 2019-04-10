#pragma once
#ifndef _CONSOLE_H
#define _CONSOLE_H
#include<iostream>				//这一页老是报错.............但还跑得通？？？？
#include<string>
#include<cstring>
#include <stdio.h> 
#include <windows.h> 
using namespace std;

class Console		//控制台类,用于修改控制台各项参数
{
public:
	Console(const char* const &name = "图书管理系统-by charon and Yvein");
	~Console();
	void cursor(bool _flag);									//显示或隐藏光标
	void setColor(char flag);

private:

};


#endif // !_CONSOLE_H

