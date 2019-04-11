#include<iostream>//这一页老是报错.............但还跑得通？？？？
#include<string>
#include<cstring>
#include <windows.h>
#include <stdio.h>
using namespace std;
#include"Console.h"

Console::Console(const char* const &name)
{
	system("title 图书管理系统-by charon and Yvein");	//设置控制台标题
	system("mode con cols=100 lines=35");				//设置宽和高
	cursor(true);										//初始化光标隐藏
}

Console::~Console()
{
}

void Console::cursor(bool flag)//显示或者隐藏光标
{
	HANDLE h_GAME = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME, &cursor_info);
	cursor_info.bVisible = flag;
	SetConsoleCursorInfo(h_GAME, &cursor_info);
}

void Console::setColor(char flag)		//设置字体颜色
{
	/*enum color
	{
		black, white, red, green, blue, yellow, pink		//首字母代表颜色
	};*/
	switch (flag)
	{
	case 'o':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY); break;
	case 'w':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE); break;
	case 'r':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); break;
	case 'g':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); break;
	case 'b':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE); break;
	case 'y':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN); break;
	case 'p':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_BLUE); break;
	default:												//默认颜色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
		break;
	}
}

void Console::color(int a) {//改变输出的颜色，比system("color x")快得多
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
	/*
	<span style="white-space:pre">	</span>字
		1	深蓝色		9	浅蓝色		背景
		2	深绿色		10	浅绿色		1~15	黑色		128~143 	灰色
		3	深青色		11	浅青色		16~31	深蓝色		144~159 	浅蓝色
		4	深红色		12	浅红色		32~47	深绿色		160~175 	浅绿色
		5	深粉色		13	浅粉色		48~63	深青色		176~191 	浅青色
		6	黄色		14	浅黄色		64~79	深红色		192~207 	浅红色
		7	深白色		15	浅白色		80~95	深粉色		208~223 	浅粉色
		8	灰色						96~111	深黄色		224~239 	浅黄色
										112~127 深白色		240~255 	浅白色							
	*/
}

int Console::check(char c) {			//检测某个按键是否按下(传入大写字母），按下就改变输出颜色
	int re = 0;
	if (!KEY_DOWN(c)) {
		color(7);
		re = 0;
	}
	else { 
		color(112); 
		re = 1;
	}
	//printf("  %c  ", c);
	color(7);
	return re;
}