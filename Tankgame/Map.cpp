#include<iostream>
using namespace std;
#include"Map.h"
#include"Console.h"

Map::Map()								//��ʼ����ս��ͼ  80*50
{
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 100; j++) {
			if (i == 0 || j == 0 || j == 97 || i == 44) {			//97����Ϊ1����Ϊ�Ǹ�ǽ���ַ�ռ����λ�ã���һλ�����һ����
				map[i][j] = 1;												//�������������ƶ�һλ������Ҳռ����
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
				if ((i == 0 || i == 44)) {
					if (jishu % 2 == 0) {
						cout << Console::U2G(n);
					}
					jishu++;
				}
				else
				{
					cout << Console::U2G(n);
				}
			}
			else if(map[i][j] == 0){
				cout << " ";
			}
			
		}
		cout << "\n";
	}
	
}