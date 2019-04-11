#include<iostream>
using namespace std;
#include"Map.h"

Map::Map()							//初始化作战地图  80*50
{
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 100; j++) {
			if (i == 0 || j == 0 || j == 99 || i == 44) {
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


void Map::showmap() {
	char map_map[45][100];
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1) {
				map_map[i][j] = '+';
			}
			else if(map[i][j] == 0){
				map_map[i][j] = ' ';
			}
			
		}
	}
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 100; j++) {
			cout << map_map[i][j];
		}
		cout << "\n";
	}
}