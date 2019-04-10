#include<iostream>
#include <stdio.h> 
#include <windows.h>
using namespace std;
#include"Console.h"
#include"KeyTest.h"

//HHOOK g_kb_hook = 0;			//检测按键的函数（虽然跟实际的按键只有字母大写符合.......
//LRESULT CALLBACK kb_proc(int code, WPARAM w, LPARAM l)
//	{
//		printf((w == WM_KEYDOWN) ? "按下%c\n" : "抬起%c\n", ((PKBDLLHOOKSTRUCT)l)->vkCode);
//		if (w == 'A')cout << "aaaaaaaaaaaaaa\n";				//自定义
//		return CallNextHookEx(g_kb_hook, code, w, l);
//	}

int main() {
	Console console;				//初始化控制台


	keytest();
}