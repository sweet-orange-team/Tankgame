#include <stdio.h> 
#include <windows.h>
#include<iostream>
using namespace std;

HHOOK g_kb_hook = 0;			//��ⰴ���ĺ�������Ȼ��ʵ�ʵİ���ֻ����ĸ��д����.......
LRESULT CALLBACK kb_proc(int code, WPARAM w, LPARAM l)
{
	printf((w == WM_KEYDOWN) ? "����%c\n" : "̧��%c\n", ((PKBDLLHOOKSTRUCT)l)->vkCode);
	if (w == 'A')cout << "aaaaaaaaaaaaaa\n";				//�Զ���
	return CallNextHookEx(g_kb_hook, code, w, l);
}
int keytest() {
	g_kb_hook = SetWindowsHookEx(WH_KEYBOARD_LL, kb_proc, GetModuleHandle(NULL), 0);		//��ʼ���������
	if (g_kb_hook == NULL)
	{
		printf("��װ���ӳ���\n"); return 0;
	};
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	};
	UnhookWindowsHookEx(g_kb_hook);
	return 0;
}