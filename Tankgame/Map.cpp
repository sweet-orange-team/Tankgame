#include<iostream>
using namespace std;
#include"Map.h"
#include"Console.h"

int Map::life = 5;
int Map::score = 0;

Map::Map()								//��ʼ����ս��ͼ  45*100
{
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 150; j++) {
			if (i == 0 || i == 44) {			//98����Ϊ1����Ϊ�Ǹ�ǽ���ַ�ռ����λ��
				if (j < 99) { 
					map[i][j][0] = 1; 
				}
				else { map[i][j][0] = 0; }
			}
			else if (j == 0 || j == 98) {
				map[i][j][0] = 1;
			}
			else
			{
				map[i][j][0] = 0;
			}
		}
	}
	{
		map[14][120][0] = 2;
		map[11][124][0] = 1;
		map[11][125][0] = 1;
		map[12][122][0] = 1;
		map[12][123][0] = 1;
		map[12][124][0] = 1;
		map[12][125][0] = 1;
		map[12][126][0] = 1;
		map[12][127][0] = 1;
		map[13][122][0] = 1;
		map[13][123][0] = 1;
		map[13][126][0] = 1;
		map[13][127][0] = 1;
	}
	map[30][120][0] = 3;
}

Map::~Map()
{

}


void Map::show() {							//ǧ�������������ж�
	Console console;
	system("cls");
	char* n = u8"��"; int jishu = 0;		//jishu�������������һ��������
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 150; j++) {
			if (map[i][j][0] == 1) {
				if (map[i][j][1] == 0) {
					console.setColor(6);
					cout << Console::U2G(n);
					j++;
					console.setColor(15);
				}
				else if (map[i][j][1] == 2) {
					console.setColor(7);
					cout << Console::U2G(n);
					j++;
					console.setColor(15);
				}
				else
				{
					cout << Console::U2G(n);
					j++;
				}
				
			}
			else if (map[i][j][0] == 2) {
				cout << "ʣ��������" << life;
			}
			else if (map[i][j][0] == 3) {
				cout << "�ܻ��֣�" << score;
			}
			else if (map[i][j][0] == 0)
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