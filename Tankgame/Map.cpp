#include<iostream>
using namespace std;
#include"Map.h"
#include"Console.h"
#include"Tank.h"

int Map::life = 5;
int Map::score = 0;

Map::Map()								//初始化作战地图  45*100
{
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 150; j++) {
			if (i == 0 || i == 44) {			//98设置为1是因为那个墙体字符占两个位置
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
		Tank tank(100, 0, 1, yellow);
		tank.append(*this, 10, 122);
	}
	map[30][120][0] = 3;
}

Map::~Map()
{

}


void Map::show() {							//千万别动这个东西，有毒
	Console console;
	system("cls");
	char* n = u8"■"; int jishu = 0;		//jishu用来隔两个输出一个■符号
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
				cout << "剩余生命：" << life;
			}
			else if (map[i][j][0] == 3) {
				cout << "总积分：" << score;
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