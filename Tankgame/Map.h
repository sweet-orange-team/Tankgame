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
	static int life;			//	  1:ǽ�壬0:�ո�,2:̹��,3:�ӵ�,4:����
	static int score;			//	��map[i][j][1]��
	int map[30][106][2];		//	  �����Ƕ��پʹ���ö����ɫ�������ɫ
};

#endif // !_MAP_H