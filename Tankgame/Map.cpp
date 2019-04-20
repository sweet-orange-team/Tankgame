#include<iostream>
using namespace std;
#include"Map.h"
#include"Console.h"

Map::Map()								//初始化作战地图  80*50
{
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 100; j++) {
			if (i == 0 || j == 0 || j == 98 || i == 44) {			//98设置为1是因为那个墙体字符占两个位置
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


void Map::show() {							//千万别动这个东西，有毒
	system("cls");
	char* n = u8"■"; int jishu = 0;		//jishu用来隔两个输出一个■符号
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