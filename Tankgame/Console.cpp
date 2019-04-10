#include<iostream>//��һҳ���Ǳ���.............�����ܵ�ͨ��������
#include<string>
#include<cstring>
using namespace std;
#include"Console.h"

Console::Console(const char* const &name)
{
	SetConsoleTitle(name);								//���ÿ���̨����
	/*�����ر���error ��BOOL GetComputerNameW(LPWSTR,LPDWORD)��: �޷������� 1 �ӡ�char [255]��ת��Ϊ��LPCWSTR�� �����
	����ȡ��ǰ��������ƣ���ǰ�˻����ƣ����߶���һ���ļ����������е�ͼƬ���ļ�������Ϊ��TLD�� CT�㷨���涼�ǻ������ġ������������Ĵ���
	����ķ�ʽ�ǣ�ѡ����Ŀ���ԡ���>�������ԡ���>���桪��>�ַ��������ַ���ѡΪ��ʹ�ö��ֽ��ַ���"���ɱ���ͨ����
	*/
	system("mode con cols=100 lines=35");				//���ÿ�͸�
	cursor(true);										//��ʼ���������
}

Console::~Console()
{
}

void Console::cursor(bool flag)//��ʾ�������ع��
{
	HANDLE h_GAME = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME, &cursor_info);
	cursor_info.bVisible = flag;
	SetConsoleCursorInfo(h_GAME, &cursor_info);
}

void Console::setColor(char flag)		//����������ɫ
{
	/*enum color
	{
		black, white, red, green, blue, yellow, pink		//����ĸ������ɫ
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
	default:												//Ĭ����ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
		break;
	}
}

