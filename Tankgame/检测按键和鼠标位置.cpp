/*
//获得鼠标X，Y数据和按键的按下与弹起
#include <stdio.h> 
#include <windows.h> 
HHOOK g_ms_hook = 0;
HHOOK g_kb_hook = 0;
LRESULT CALLBACK kb_proc(int code, WPARAM w, LPARAM l)
{
	printf((w == WM_KEYDOWN) ? "按下%c\n" : "抬起%c\n", ((PKBDLLHOOKSTRUCT)l)->vkCode);
	return CallNextHookEx(g_kb_hook, code, w, l);
}
LRESULT CALLBACK ms_proc(int code, WPARAM w, LPARAM l)
{
	if (w == WM_LBUTTONDOWN) printf("按下左键\n"); else if (w == WM_LBUTTONUP) printf("抬起左键\n");
	else printf("x:%d\ty:%d\n", ((PMSLLHOOKSTRUCT)l)->pt.x, ((PMSLLHOOKSTRUCT)l)->pt.y);
	return CallNextHookEx(g_ms_hook, code, w, l);
}
int main(void)
{
	g_kb_hook = SetWindowsHookEx(WH_KEYBOARD_LL, kb_proc, GetModuleHandle(NULL), 0);
	g_ms_hook = SetWindowsHookEx(WH_MOUSE_LL, ms_proc, GetModuleHandle(NULL), 0);
	if (g_kb_hook == NULL || g_ms_hook == NULL)
	{
		printf("安装钩子出错\n"); return 0;
	};
	MSG msg; while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	};
	UnhookWindowsHookEx(g_kb_hook);
	return 0;
};
*/