#include<iostream>
using namespace std;
#include"Map.h"
#include"Console.h"

Map::Map()								//初始化作战地图  80*50
{
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 100; j++) {
			if (i == 0 || j == 0 || j == 97 || i == 44) {			//97设置为1是因为那个墙体字符占两个位置，第一位多出来一个，
				map[i][j] = 1;												//所以依次往后移动一位，最后的也占两格
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