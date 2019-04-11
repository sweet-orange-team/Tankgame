#include<iostream>
#include <stdio.h> 
#include <windows.h>
using namespace std;
#include"Console.h"
#include"Control.h"
#include"Map.h"

char* U2G(char* utf8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1]; memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1]; memset(str, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr; return str;
}


int main() {
	Console console;				//��ʼ������̨
	Map map;						//��ʼ����ͼ
	map.showmap();					//�����ͼ
	


	system("pause");
	return 0;
}