#include<iostream>
#include <stdio.h> 
#include <windows.h>
using namespace std;
#include"Console.h"
#include"KeyTest.h"

//HHOOK g_kb_hook = 0;			//��ⰴ���ĺ�������Ȼ��ʵ�ʵİ���ֻ����ĸ��д����.......
//LRESULT CALLBACK kb_proc(int code, WPARAM w, LPARAM l)
//	{
//		printf((w == WM_KEYDOWN) ? "����%c\n" : "̧��%c\n", ((PKBDLLHOOKSTRUCT)l)->vkCode);
//		if (w == 'A')cout << "aaaaaaaaaaaaaa\n";				//�Զ���
//		return CallNextHookEx(g_kb_hook, code, w, l);
//	}

int main() {
	Console console;				//��ʼ������̨


	keytest();
}