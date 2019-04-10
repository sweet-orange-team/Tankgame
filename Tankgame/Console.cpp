#include<iostream>//这一页老是报错.............但还跑得通？？？？
#include<string>
#include<cstring>
using namespace std;
#include"Console.h"

Console::Console(const char* const &name)
{
	SetConsoleTitle(name);								//设置控制台标题
	/*（神秘报错，error “BOOL GetComputerNameW(LPWSTR,LPDWORD)”: 无法将参数 1 从“char [255]”转换为“LPCWSTR” 解决）
	当获取当前计算机名称，当前账户名称，或者读入一个文件夹里面所有的图片的文件名。因为在TLD， CT算法里面都是会遇到的。会遇到这样的错误。
	解决的方式是：选中项目属性——>配置属性——>常规——>字符集，就字符集选为“使用多字节字符集"即可编译通过。
	*/
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

