#include<iostream>										//��һҳ���Ǳ���.............�����ܵ�ͨ��������										//
#include <windows.h>
using namespace std;
#include"Console.h"

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

Console::Console()
{
	system("title TankGame-by charon and Yvein");		//���ÿ���̨����
	//system("mode con cols=160 lines=50");				//���ó�160�Ϳ�50
	setCursorSee(false);								//��ʼ���������
	//system("chcp 65001");								//����֧��unicode--���utf-8�ַ�ʱ������ᱨ��
														//�����µĿ���̨������
	hOutBuf = CreateConsoleScreenBuffer(
		GENERIC_WRITE,									//������̿�����������д����
		FILE_SHARE_WRITE,								//���建�����ɹ���дȨ��
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	hOutput = CreateConsoleScreenBuffer(
		GENERIC_WRITE,									//������̿�����������д����
		FILE_SHARE_WRITE,								//���建�����ɹ���дȨ��
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
}

Console::~Console()
{
}

void Console::setCursorPosition(const int x, const int y)	//���ù��λ��,����x������y
{
	COORD position;
	position.X = y;
	position.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void Console::setCursorSee(bool flag)					//��ʾ�������ع��
{
	HANDLE h_GAME = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME, &cursor_info);
	cursor_info.bVisible = flag;
	SetConsoleCursorInfo(h_GAME, &cursor_info);
}


void Console::setColor(int number) {					//�ı��������ɫ����system("color x")��ö�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), number);
	/*	��������ֵ���ɫ						������ñ�����ɫ
	��
		1	����ɫ		9	ǳ��ɫ	||||	����
		2	����ɫ		10	ǳ��ɫ	||||	1~15	��ɫ		128~143 	��ɫ
		3	����ɫ		11	ǳ��ɫ	||||	16~31	����ɫ		144~159 	ǳ��ɫ
		4	���ɫ		12	ǳ��ɫ	||||	32~47	����ɫ		160~175 	ǳ��ɫ
		5	���ɫ		13	ǳ��ɫ	||||	48~63	����ɫ		176~191 	ǳ��ɫ
		6	��ɫ		14	ǳ��ɫ	||||	64~79	���ɫ		192~207 	ǳ��ɫ
		7	���ɫ		15	ǳ��ɫ	||||	80~95	���ɫ		208~223 	ǳ��ɫ
		8	��ɫ					||||	96~111	���ɫ		224~239 	ǳ��ɫ
									||||	112~127 ���ɫ		240~255 	ǳ��ɫ
		15��Ĭ��������ɫ��Ĭ�ϱ����Ǻ�ɫ
	*/
}

/*
//			cout << "��ð���" << endl;			 	setColor(red);
//		};										 	re = 0;
//												 }

//	while (1) {									 int re = 0;
//		if (console.check('Q')) {				 if (!KEY_DOWN(key)) {
//			cout << "��ð���" << endl;			 	setColor(red);
//		};										 	re = 0;
//												 }
//		Sleep(20);//ѭ��ʱ��������ֹ̫ռ�ڴ�	else {
	//		//system("cls");//���� 			   	setColor(white);
//	}											 	re = 1;
//												 }
//												 printf("  %c  ", key);
//												 setColor(7);
//												 return re;
*/
void Console::checkKey(Tank &mytank) {			//���ĳ�������Ƿ���(�����д��ĸ�������¾͸ı������ɫ
	while (true)
	{
		if (KEY_DOWN('W')) {
			mytank.move(0);
			Sleep(150);
		}else 
		if (KEY_DOWN('S')) {
			//cout << "S";
			mytank.move(1);
			Sleep(150);
		}else 
		if (KEY_DOWN('A')) {
			mytank.move(2);
			Sleep(150);
		}else 
		if (KEY_DOWN('D')) {
			mytank.move(3);
			Sleep(150);
		}else 
		if (KEY_DOWN(' ')) {
			mytank.shoot();
			Sleep(150);
		}else 
		if (KEY_DOWN('Z')) {
			break;
		}
		else continue;

	}
}

char* Console::U2G(char* utf8)			//���ɵ�UTF-8ת����
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1]; memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}