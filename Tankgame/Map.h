#pragma once
#ifndef _MAP_H
#define _MAP_H
class Map
{
public:
	static int handle;
	Map();						//map[][][]˵����
	~Map();						//	ǰ����ά�ȶ����꣬������ά�ȶ���ɫ
	void show();				//	��map[i][j][0]��
	static int life;			//	  ����1����ǽ�壬����0����ո�����2����ʣ������������3�����ܷ�
	static int score;			//	��map[i][j][1]��
	int map[45][150][2];		//	  �����Ƕ��پʹ���ö����ɫ�������ɫ
};

#endif // !_MAP_H