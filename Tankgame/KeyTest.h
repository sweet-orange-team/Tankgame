#include <stdio.h> 
#include <windows.h>
#include<iostream>
using namespace std;

HHOOK g_kb_hook = 0;			//检测按键的函数（虽然跟实际的按键只有字母大写符合.......
LRESULT CALLBACK kb_proc(int code, WPARAM w, LPARAM l)
{
	printf((w == WM_KEYDOWN) ? "按下%c\n" : "抬起%c\n", ((PKBDLLHOOKSTRUCT)l)->vkCode);
	if (w == 'A')cout << "aaaaaaaaaaaaaa\n";				//自定义
	return CallNextHookEx(g_kb_hook, code, w, l);
}
int keytest() {
	g_kb_hook = SetWindowsHookEx(WH_KEYBOARD_LL, kb_proc, GetModuleHandle(NULL), 0);		//初始化按键检测
	if (g_kb_hook == NULL)
	{
		printf("安装钩子出错\n"); return 0;
	};
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	};
	UnhookWindowsHookEx(g_kb_hook);
	return 0;
}