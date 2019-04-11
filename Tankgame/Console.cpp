#include<iostream>										//这一页老是报错.............但还跑得通？？？？										//
#include <windows.h>									//									//
using namespace std;
#include"Console.h"

Console::Console()
{
	system("title TankGame-by charon and Yvein");		//设置控制台标题
	system("mode con cols=160 lines=50");				//设置长160和宽45
	setCursorSee(false);								//初始化光标隐藏
	//system("chcp 65001");								//设置支持unicode--输出utf-8字符时用这个会报错
}

Console::~Console()
{
}

void Console::setCursorPosition(const int x, const int y)	//设置光标位置
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void Console::setCursorSee(bool flag)					//显示或者隐藏光标
{
	HANDLE h_GAME = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME, &cursor_info);
	cursor_info.bVisible = flag;
	SetConsoleCursorInfo(h_GAME, &cursor_info);
}


void Console::setColor(int number) {					//改变输出的颜色，比system("color x")快得多
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), number);
	/*	这边设置字的颜色						这边设置背景颜色
	字
		1	深蓝色		9	浅蓝色	||||	背景
		2	深绿色		10	浅绿色	||||	1~15	黑色		128~143 	灰色
		3	深青色		11	浅青色	||||	16~31	深蓝色		144~159 	浅蓝色
		4	深红色		12	浅红色	||||	32~47	深绿色		160~175 	浅绿色
		5	深粉色		13	浅粉色	||||	48~63	深青色		176~191 	浅青色
		6	黄色		14	浅黄色	||||	64~79	深红色		192~207 	浅红色
		7	深白色		15	浅白色	||||	80~95	深粉色		208~223 	浅粉色
		8	灰色					||||	96~111	深黄色		224~239 	浅黄色
									||||	112~127 深白色		240~255 	浅白色							
	*/
}

int Console::checkKey(char key) {			//检测某个按键是否按下(传入大写字母），按下就改变输出颜色
	int re = 0;							//		while (1) {
	if (!KEY_DOWN(key)) {					//			if (console.check('Q')) {
		setColor(7);						//				cout << "你好啊！" << endl;
		re = 0;							//			};
	}									//			
	else { 								//			Sleep(20);//循环时间间隔，防止太占内存
		setColor(112); 					//			//system("cls");//清屏 
		re = 1;							//		}
	}									//
	//printf("  %c  ", c);				//
	setColor(7);							//
	return re;							//
}

char* Console::U2G(char* utf8)			//神仙的uft-8，转换！
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1]; memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1]; memset(str, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr; return str;
}