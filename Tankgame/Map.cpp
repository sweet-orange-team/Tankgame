#include<iostream>
using namespace std;
#include"Map.h"
#include"Console.h"

Map::Map()								//��ʼ����ս��ͼ  80*50
{
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 100; j++) {
			if (i == 0 || j == 0 || j == 98 || i == 44) {			//98����Ϊ1����Ϊ�Ǹ�ǽ���ַ�ռ����λ��
				map[i][j] = 1;
			}
			else
			{
				map[i][j] = 0;
			}
		}
	}
}

Map::~Map()
{
}


void Map::show() {							//ǧ�������������ж�
	system("cls");
	char* n = u8"��"; int jishu = 0;		//jishu�������������һ��������
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1) {
				cout << Console::U2G(n);
				j++;
			}
			else
			{
				cout << " ";
			}	
		}
		cout << "\n";

	}
}