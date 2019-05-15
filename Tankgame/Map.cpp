#include<iostream>
#include<stdio.h>
using namespace std;
#include"Map.h"
#include"Console.h"
#include"Tank.h"


int Map::map[30][106][2] = { { {0} } };

Map::Map()								//��ʼ����ս��ͼ  29*79
{
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 106; j++) {			//���ճ���ʼ��ͼ
			if (i == 0 || i == 29) {			//78����Ϊ1����Ϊ�Ǹ�ǽ���ַ�ռ����λ��
				if (j < 80) {
					map[i][j][0] = 1;
				}
				else { map[i][j][0] = 0; }
			}
			else if (j == 0 || j == 78) {
				map[i][j][0] = 1;
			}
			else
			{
				map[i][j][0] = 0;
			}
		}
	}
	{							//���ø����ָ���
		for (int i = 82; i < 106; i++)map[4][i][0] = 1;
		for (int i = 82; i < 106; i++)map[10][i][0] = 1;
		for (int i = 82; i < 106; i++)map[16][i][0] = 1;
		for (int i = 82; i < 106; i++)map[22][i][0] = 1;
		for (int i = 82; i < 106; i++)map[29][i][0] = 1;

		map[7][90][0] = 2;
		map[13][90][0] = 3;
	}
}

Map::~Map()
{
}


void Map::show() {							//ǧ�������������ж�
	Console console;
	system("cls");
	char* n = u8"��"; int jishu = 0;		//jishu�������������һ��������
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 106; j++) {
			if (map[i][j][0] == 1) {
				printf(Console::U2G(n));
				j++;
			}
			else if (map[i][j][0] == 2) {
				Console::setColor(red);
				cout << "ʣ��������" << Tank::blood;
				Console::setColor(15);
			}
			else if (map[i][j][0] == 3) {
				Console::setColor(green);
				cout << "�ܻ��֣�" << Tank::score;
				Console::setColor(15);
			}
			else if (map[i][j] == 0)
			{
				cout << " ";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
}

void Map::refresh()
{
	Console::setCursorPosition(7, 90);
	Console::setColor(red);
	cout << "ʣ��������" << Tank::blood;
	Console::setColor(15);
	Console::setCursorPosition(13, 90);
	Console::setColor(green);
	cout << "�ܻ��֣�" << Tank::score;
	Console::setColor(15);
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 106; j++) {
			for (int k = 0; k < 2; k++) {
				privateMap[i][j][k] = Map::map[i][j][k];
			}
		}
	}
}
